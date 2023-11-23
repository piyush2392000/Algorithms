#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int w;
	cin>>n;
	cin>>w;
	vector<int>wt(n);
	vector<int>val(n);
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}

	vector<vector<int>>dp(n+1,vector<int>(w+1));
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0||j==0)
				{dp[i][j]=0;}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(wt[i-1]<=j)
			{
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<< dp[n][w];
}