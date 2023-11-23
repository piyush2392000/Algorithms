#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>dp(n+1,1e9); // dp[i]->represents min no of steps to reach 0 from i
    dp[0]=0;
	for(int i=1;i<n+1;i++)
	{
		int num=i;
		while(num>0)
		{
			int digit=num%10;
			num=num/10;
			dp[i]=min(dp[i],1+dp[i-digit]);
		}
	}
	cout<< dp[n];
}