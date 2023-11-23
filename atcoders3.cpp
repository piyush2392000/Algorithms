#include <bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>&a,vector<vector<int>>&dp)
{
	if(day==0)
	{
		int maxi=0;
		for(int i=0;i<3;i++)
		{
			if(i!=last)
			{
				maxi=max(maxi,a[0][i]);
			}
		}
		return maxi;
	}
    if(dp[day][last]!=-1){return dp[day][last];}
	int maxi=0;
	for(int i=0;i<3;i++)
	{
		if(i!=last)
			{
				int point=a[day][i]+f(day-1,i,a,dp);
				maxi=max(maxi,point);
			}

	}
	return dp[day][last]=maxi;

}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>a(n,vector<int>(3));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	vector<vector<int>>dp(n,vector<int>(4,-1));
	cout<<f(n-1,3,a,dp);
	/*vector<vector<int>>dp(n,vector<int>(4,0));
	
	dp[0][0]=max(a[0][1],a[0][2]);
	dp[0][1]=max(a[0][0],a[0][2]);
	dp[0][2]=max(a[0][0],a[0][1]);
	dp[0][3]=max(a[0][1],max(a[0][2],a[0][0]));
	for(int day=1;day<n;day++)
	{
		for(int last=0;last<4;last++)
		{
			dp[day][last]=0;
	        for(int task=0;task<3;task++)
	        {
                  int point=a[day][task]+dp[day-1][task];
                  dp[day][last]=max(dp[day][last],point);
	        }

		}
	}
	return dp[n-1][3];
	*/

}