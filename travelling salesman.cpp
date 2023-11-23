// tarvelling salesman problem
#include <bits/stdc++.h>
using namespace std;
int tsp(int mask,int pos,vector<vector<int>>&nums,int n,int allvis)
{
    if(mask==allvis)
    {
        return nums[pos][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            int temp=nums[pos][i]+tsp(mask|(1<<i),i,nums,n,allvis);
            ans=min(temp,ans);
        }
    }
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>nums(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>nums[i][j];
            }
        }
        int allvis=(1<<n)-1;
        cout<<tsp(1,0,nums,n,allvis)<<endl;
    }
    return 0;
}