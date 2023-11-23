#include <bits/stdc++.h>
using namespace std;
const N=1e3+10;
int graph1[N][N];
vector<pair<int,int>>graph(N);



int main()
{
	int n,m; //no of vertices,no of edges
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int v1,v2,wt;
		cin>>v1>>v2>>wt;
		graph1[v1][v2]=wt;
		graph1[v2][v1]=wt;

		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}

}