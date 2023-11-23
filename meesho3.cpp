#include <bits/stdc++.h>
using namespace std;
class disjointset
{
	public:
	vector<int>rank,parent,size;
    disjointset(int n)
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
	int n;
	cin>>n;
	int e;
	cin>>e;
	vector<vector<int>>edges(e,vector<int>(2));
	for(int i=0;i<e;i++)
	{
		cin>>edges[i][0]>>edges[i][1];
	}
	int q;
	cin>>q;
	vector<int>que(q);
	for(int i=0;i<q;i++)
	{
		cin>>que[i];
	}
	disjointset ds(n);
	for(int i=0;i<e;i++)
	{
		ds.unionbysize(edges[i][0],edges[i][1]);
	}
	vector<int>ans(q);
	for(int i=0;i<q;i++)
	{
		ans[i]=ds.size[ds.parent[que[i]]];
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<" ";
	}


}