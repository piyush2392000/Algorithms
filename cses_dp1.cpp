#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
	cin>>n;
	int mod=1e9+7;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	vector<int>dp(n+1,0);
	dp[0]=1;
	for(int i=1;i<n+1;i++)
	{
		
		for(int k=1;k<=6;k++)
		{
			if(k>i){continue;}
            dp[i]=(dp[i]+dp[i-k])%mod;
			
		}
		

	}
	cout<< dp[n]%mod;
}