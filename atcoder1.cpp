#include <bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>a,vector<int>&dp,int k)
{
	if(ind==0)
	{
		return 0;
	}
	if(dp[ind]!=-1){return dp[ind];}
	/*int l=f(ind-1,a,dp)+abs(a[ind]-a[ind-1]);
	int r=INT_MAX;
	if(ind>1){
	 r=f(ind-2,a,dp)+abs(a[ind]-a[ind-2]);}*/
    int mincost=INT_MAX;
	for(int j=1;j<=k;j++)
	{
		if(ind-j>=0)
		{
			int l=f(ind-j,a,dp,k)+abs(a[ind]-a[ind-j]);
			mincost=min(mincost,l);
		}

	}
	return dp[ind]=mincost;

}


