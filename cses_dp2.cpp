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
	vector<int>dp(sum+1,1e9);
	dp[0]=0;
    for(int i=0;i<sum+1;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(nums[j]>i){continue;}
    		dp[i]=min(dp[i],1+dp[i-nums[j]]);
    	}
    }
    if(dp[sum]==1e9)
    {
        cout<<-1;
    	return 0;
    }
    cout<<dp[sum];
}