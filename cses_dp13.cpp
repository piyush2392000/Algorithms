#include <bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>&piles,vector<vector<int>>&dp,int m)
{
    if(ind>=piles.size()){return 0;}
    if(dp[ind][m]!=-1){return dp[ind][m];}
    int total=0;
    int ans=INT_MIN;
    for(int i=0;i<2*m;i++)
    {
        if(i+ind<piles.size()){total+=piles[i+ind];}
        ans=max(ans,total-f(i+ind+1,piles,dp,max(m,i+1)));
    }
    return dp[ind][m]=ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>piles(n);
    for(int i=0;i<n;i++)
    {
        cin>>piles[i];
    }
    vector<vector<int>>dp(piles.size()+1,vector<int>(1001,-1));
    int m=1;
    int sum=0;
    for(int i=0;i<piles.size();i++)
    {
         sum+=piles[i];
    }

    cout<< (f(0,piles,dp,m)+sum)/2;
}