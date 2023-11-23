#include <bits/stdc++.h>
using namespace std;
void dfs(int r,int c,vector<vector<char>>mp,vector<vector<int>>&vis,int n,int m,int dr[],int dc[])
{
	vis[r][c]=1;
	
	for(int i=0;i<4;i++)
	{
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&mp[nr][nc]=='.')
		{
			dfs(nr,nc,mp,vis,n,m,dr,dc);
		}
	}

}

int main()
{
int n,m;
cin>>n>>m;
vector<vector<char>>mp(n,vector<char>(m));
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		cin>>mp[i][j];
	}
}
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
vector<vector<int>>vis(n,vector<int>(m,0));
int count=0;
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		if(vis[i][j]==0&&mp[i][j]=='.')
		{
			count++;
			dfs(i,j,mp,vis,n,m,dr,dc);
		}
		
	}
}
cout<<count;
return 0;
}