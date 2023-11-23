#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vectror<vector<int>>cc;
vector<vector<int>>g(N);
bool visited[N];
void dfs(int vertex)
{
	//take action on vertex after entering the vertex
	visited[vertex]=1;
	for(int child:g[vertex])
	{
		//take action on child before entering the child node 
		if(visited[child])continue;
		dfs(child);
		//take action on child after exiting the child node
    }
	//take action on vertex before exiting the vertex
}



int main()
{
	int n,m; //no of vertices,no of edges
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int v1,v2;
		cin>>v1>>v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	//dfs(1);

	int count=0;
	for(int i=1;i<=n;++i)
	{

		if(visited[i]) continue;
		dfs(i);
		count++;
	}
	cout<<count;




}