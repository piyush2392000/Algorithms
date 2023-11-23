#include <bits/stdc++.h>
using namespace std;
long long f(int n,int w,vector<int>wt,vector<int>v,vector<vector<long long>>&dp)
{
	if(n==0||w==0){return 0;}
	if(dp[n][w]!=-1){return dp[n][w];}
	if(w>=wt[n-1])
	{
		dp[n][w]=max(v[n-1]+f(n-1,w-wt[n-1],wt,v,dp),f(n-1,w,wt,v,dp));
	}
	if(w<wt[n-1])
	{
		dp[n][w]=f(n-1,w,wt,v,dp);
	}
	return dp[n][w];
}
int main()
{
	int n;
	cin>>n;
	int w;
	cin>>w;
	vector<int>v(n);
	vector<int>wt(n);
	vector<vector<long long>>dp(n+1,vector<long long>(w+1,-1));
	for(int i=0;i<n;i++)
	{
		cin>>wt[i]>>v[i];
	}

	cout<<f(n,w,wt,v,dp);
   
}