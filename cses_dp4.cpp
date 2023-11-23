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
	sort(nums.begin(),nums.end());
	vector<int>dp(sum+1,0);
	dp[0]=1;
	for(auto coin:nums)
	{
		for(int j=coin;j<=sum;j++)
		{

			dp[j]=(dp[j]+dp[j-coin])%mod;
		}
	}
	cout<<dp[sum];

}