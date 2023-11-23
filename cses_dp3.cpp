#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int sum;
	int mod=1e9+7;
	cin>>n;
	cin>>sum;
	vector<int>nums(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	vector<int>dp(sum+1,0);
	dp[0]=1;
	for(int i=1;i<sum+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(nums[j]>i){continue;}
			dp[i]=(dp[i]+dp[i-nums[j]])%mod;
		}
	}
	cout<<dp[sum];
	
}