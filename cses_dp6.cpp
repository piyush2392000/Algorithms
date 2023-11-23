#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main()
{
	//int mod=1e9+7;
	int n;
	cin>>n;
	vector<vector<char>>grid(n,vector<char>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	if(grid[0][0]=='*'||grid[n-1][n-1]=='*'){cout<<0;return 0;}
    vector<vector<int>>dp(n,vector<int>(n));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='*'){dp[i][j]=0;}
            else if(i==0&&j==0){dp[i][j]=1;}
            else
            {
               int up=0;
               int left=0;
               if(i>0) up=dp[i-1][j];
               if(j>0) left=dp[i][j-1];
               dp[i][j]=(up+left)%mod;
            }
        }
    }
    cout<<dp[n-1][n-1];

}