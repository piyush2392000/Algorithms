#include <bits/stdc++.h>
using namespace std;

int main()
{
	int v,m;
	cin>>v>>m;
	vector<int>adj[v];
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].push_back(y);
	}
	vector<int>vis(v,0);
    vector<int>indegree(v,0);
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
              q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    if(topo.size()==v)
    {
         for(int i=0;i<v;i++)
         {
            cout<<topo[i]+1<<' ';
         }
    	
    }
    else{cout<<"IMPOSSIBLE";}
   
	return 0;
}