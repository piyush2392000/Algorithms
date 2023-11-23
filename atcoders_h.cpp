#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,int n,int m,vector<vector<char>>&a,vector<vector<int>>&dp)
{
	if(a[i][j]=='#'){return 0;}
	if(i==n-1&&j==m-1)
	{
		return 1;
	}
	if(i>n-1||j>m-1){return 0;}
	
	if(dp[i][j]!=-1)
		return dp[i][j];

	int up=f(i+1,j,n,m,a,dp);
	int down=f(i,j+1,n,m,a,dp);
	return dp[i][j]=(up+down)%1000000007;
}

int main()
{
	int n,m;
	cin>>n;
	cin>>m;

	vector<vector<char>>a(n,vector<char>(m));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{

			cin>>a[i][j];
		}
    }
	vector<vector<int>>dp(n,vector<int>(m,-1));

	cout<<f(0,0,n,m,a,dp);
	return 0;
	
}