#include <bits/stdc++.h>
using namespace std;
// lis
int f(int ind,int prev_ind,vector<int>&nums)
{
    if(ind==nums.size()){return 0;}
    int len=0+f(ind+1,prev_ind,nums); //not take
    if(prev_ind==-1||nums[ind]>nums[prev_ind])
    {
        len=max(len,1+f(ind+1,ind,nums)); // take or not take based on max
    }
    return len;
}
int lis(vector<int>&nums)
{
    return f(0,-1,nums); 
}




// lis tabulation
vector<int>listab(vector<int>nums)
{
    int n=nums.size();
    vector<int>dp(n,1);
    int maxi=0;
    int last_index=0;
    vector<int>hash(n);
    for(int ind=0;ind<n;ind++)
    {
        for(int prev=0;prev<ind+1;prev++)
        {
            if(nums[ind]>nums[prev]&&dp[ind]<dp[prev]+1)
            {
                dp[ind]=dp[prev]+1;
                hash[ind]=prev;
            }
        }
        if(maxi<dp[ind])
        {
           maxi=dp[ind];
           last_index=ind;
        }
    }
    vector<int>ans;
    ans.push_back(nums[last_index]);
    while(hash[last_index]!=last_index)
    {
        last_index=hash[last_index];
        ans.push_back(nums[last_index]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

// count of lis
int countof_lis(vector<int>nums)
{
    int n=nums.size();
    vector<int>dp(n,1);
    int maxi=0;
    int last_index=0;
    int cnt=0;
    vector<int>count(n,1);
    for(int ind=0;ind<n;ind++)
    {
        for(int prev=0;prev<ind+1;prev++)
        {
            if(nums[ind]>nums[prev]&&dp[ind]<dp[prev]+1)
            {
                dp[ind]=dp[prev]+1;
                count[ind]=count[prev];
            }
            else if(nums[ind]>nums[prev]&&dp[ind]<dp[prev]+1)
            {
                count[ind]+=count[prev];
            }
        }
        if(maxi<dp[ind])
        {
           maxi=dp[ind];
           cnt=count[ind];
        }
    }
    

}

// lis using binary search    (vvvvvip)
int lis_binary_search(vector<int>nums)
{
    int n=nums.size();
    vector<int>temp;
    temp.push_back(nums[0]);
    int len=1;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
        else
        {
            auto ind=lower_bound(temp.begin(),temp.end(),nums[i]);
            temp[ind]=nums[i];
        }
    }
    return len;
}












vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1),hash(n);
        int maxi=1;
        int last_index=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
                if(maxi<dp[i])
                {
                    maxi=dp[i];
                    last_index=i;
                }
                
            }  
        }
        vector<int>temp;
        temp.push_back(nums[last_index]);
        while(hash[last_index]!=last_index)
        {
            last_index=hash[last_index];
            temp.push_back(nums[last_index]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
        
    }

// longest string chains



int longestbitonicarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp1[i]<dp1[j]+1&&nums[i]>nums[j])
                {
                    dp1[i]=1+dp1[j];
                }
            }
        }
        vector<int>dp2(n,1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(dp2[i]<dp2[j]+1&&nums[i]>nums[j])
                {
                    dp2[i]=1+dp2[j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if (dp1[i] > 1 && dp2[i] > 1) {
                ans = max(dp1[i] + dp2[i] - 1, ans);
            }
        }

        return ans;

        
    }    
int main()
{
   int n;
   cin>>n;
   
   vector<int>nums(n);
   
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  cout<<lis_binary_search(nums);
  /*
  vector<int>ans=listab(nums);
  for(auto it:ans)
  {
    cout<<it<<" ";
  }     
   */

   

   
}