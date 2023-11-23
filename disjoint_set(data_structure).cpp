#include <bits/stdc++.h>
using namespace std;
class Disjointset
{
	vector<int>rank,parent,size;
public:
    Disjointset(int n)
    {   
        rank.resize(n+1,0);
    	parent.resize(n+1);
    	size.resize(n+1);
    	for(int i=0;i<n+1;i++)
    	{
    		parent[i]=i;
    		size[i]=1;
    	}
    }
    int findupar(int node)
    {
    	if(node==parent[node]){return node;}
    	return parent[node]=findupar(parent[node]);  //path compression
    }
    void unionbyrank(int u,int v)
    {
    	int ulp_u=findupar(u);
    	int ulp_v=findupar(v);
    	if(ulp_u==ulp_v){return;}
    	if(rank[ulp_u]<rank[ulp_v]){parent[ulp_u]=ulp_v;}
    	else if(rank[ulp_v]<rank[ulp_u]){parent[ulp_v]=ulp_u;}
    	else
    		{
    			parent[ulp_v]=ulp_u;
    			rank[ulp_u]++;
    		}

    }
    void unionbysize(int u,int v)
    {
    	int ulp_u=findupar(u);
    	int ulp_v=findupar(v);
    	if(ulp_u==ulp_v){return;}
    	if(size[ulp_u]<size[ulp_v])
    		{
    			parent[ulp_u]=ulp_v;
    			size[ulp_v]+=size[ulp_u];
    		}
    	else
    		{
    			parent[ulp_v]=ulp_u;
    			size[ulp_u]+=size[ulp_v];
    		}

    }	
};
int main()
{
	Disjointset ds(7);
	ds.unionbyrank(1,2);
	ds.unionbyrank(2,3);
	ds.unionbyrank(4,5);
	ds.unionbyrank(6,7);
	ds.unionbyrank(5,6);
	ds.unionbyrank(3,7);
	
   
    return 0;
}