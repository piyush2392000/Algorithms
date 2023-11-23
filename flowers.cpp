#include <bits/stdc++.h>
using namespace std;
int f(int ind,int prev_ind,vector<int>&h,vector<int>&b,int n)
{
   if(ind==n)
   {
      return 0;
   }

   
   int  ans= f(ind+1,prev_ind,h,b,n);
   
   if(prev_ind==-1||h[prev_ind]<h[ind])
   {
      ans=max(b[ind]+f(ind+1,ind,h,b,n),ans);
   }
   return ans;
}
int main()
{
   int n;
   cin>>n;
   vector<int>h(n);
   vector<int>b(n);
   for(int i=0;i<n;i++)
   {
   	  cin>>h[i];
   }
   for(int i=0;i<n;i++)
   {
        cin>>b[i];
   }
   

  // cout<<f(n-1,-1,h,b,n);
int n=nums.size();
        
        vector<int>dp(n+1,1),hash(n);
        int maxi=1;
        int last_index=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]==0&&dp[i]<1+dp[j])
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

   
}