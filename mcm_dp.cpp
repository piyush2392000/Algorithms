#include <bits/stdc++.h>
using namespace std;
//matrix chain multiplication
//ex:{10,20,30,40,30}
int f1(int i,int j,vector<int>arr,vector<vector<int>>&dp)
{
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+f1(i,k,arr,dp)+f1(k+1,j,arr,dp);
        ans=min(steps,ans);
    }
    return dp[i][j]=ans;
}






 //minimium cost to cut stick
 int fn(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int mini=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int cost=cuts[j+1]-cuts[i-1]+fn(i,k-1,cuts,dp)+fn(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return fn(1,c,cuts,dp);
        
    }



//burst ballons
/*
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/
int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++)
        {
            int coin=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
            maxi=max(maxi,coin);
        }
        return dp[i][j]=maxi;
        

        
    }
    int burstballons(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
        
    }


int main()
{

	int  n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	cout<<burstballons(nums);

    
}