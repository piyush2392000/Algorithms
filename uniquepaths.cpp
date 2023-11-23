#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&dp,vector<vector<char>>&a)
{
        if(i>=0&&j>=0&&a[i][j]=='#'){return 0;}
        if(i==0&&j==0){return 1;}
        if(i<0||j<0){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int up=f(i-1,j,dp,a);
        int left=f(i,j-1,dp,a);
        return dp[i][j]=(up+left)%1000000007;
}
int main()
{
    int m;
    int n;
    cin>>m;
    cin>>n;
    int mod=1e9+7;
    vector<vector<char>>a(m,vector<char>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    cout<<f(m-1,n-1,dp,a)%mod;
}