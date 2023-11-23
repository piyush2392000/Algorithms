// dp on grids and 1d dp problems
#include <bits/stdc++.h>
using namespace std;
// count paths in a grid 
/*There is a robot on an m x n grid. The robot is initially located at the 
top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right
corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right
at any point in time.Given the two integers m and n, 
return the number of possible unique paths that the robot can take 
to reach the bottom-right corner.
*/
int countpaths(int i,int j)// no of paths to reach from {m,n} to {0,0}
{
    if(i==0&&j==0)
    {
        return 1;
    }
    if(i<0||j<0)
    {
        return 0;
    }
    int up=countpaths(i-1,j);
    int left=countpaths(i,j-1);
    return up+left;
}
int countpathstab(int m,int n)  //tabulation
{
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    dp[0][0]=1;
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0&&j==0){dp[i][j]=1;}
            else if(i==0||j==0){dp[i][j]=1;}
            else
            {
               int up=0;
               int left=0;
               if(i>0) up=dp[i-1][j];
               if(j>0) left=dp[i][j-1];
               dp[i][j]=up+left;
            }
        }
    }
    return dp[m][n];
}




//unique_paths2
/*You are given an m x n integer array grid. There is a robot initially located
at the top-left corner (i.e., grid[0][0]). The robot tries to move to the 
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that 
the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach 
the bottom-right corner.*/
int uniquepathtab(int m,int n,vector<vector<int>>&grid)
{
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    dp[0][0]=1;
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(grid[i][j]==1){dp[i][j]=0;}
            else if(i==0&&j==0){dp[i][j]=1;}
            else
            {
               int up=0;
               int left=0;
               if(i>0) up=dp[i-1][j];
               if(j>0) left=dp[i][j-1];
               dp[i][j]=up+left;
            }
        }
    }
    return dp[m][n];
}


// minimum path sum    (fixed src->fixed destination)
/*Given a m x n grid filled with non-negative numbers, find a path from top 
left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
*/
int f(int i,int j,vector<vector<int>>&grid)
{
    if(i==0&&j==0)
        {return grid[i][j];}
    if(i<0||j<0)
        {return INT_MAX;}
    int up=grid[i][j]+f(i-1,j,grid);
    int left=grid[i][j]+f(i,j-1,grid);
    return min(up,left);
}
int minimumpathsum(int m,int n,vector<vector<int>>&grid)
{
    // return f(m,n,grid);
    //tabulation
    vector<vector<int>>dp(m+1,vector<int>(n+1)); //dp[i][j]->represents min path sum till index(i,j) 
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0&&j==0){dp[i][j]=grid[0][0];}
            //else if(i==0){dp[i][j]=dp[i][j-1]+grid[i][j];}
            //else if(j==0){dp[i][j]=dp[i-1][j]+grid[i][j];}
            else
            {
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>=1){up=dp[i-1][j];}
                if(j>=1){left=dp[i][j-1];}
                dp[i][j]=grid[i][j]+min(up,left);
            }

        }
    }
    return dp[m][n];   
}
// triangle     (fixed starting ->variable ending point)
/*i/p:
1
2 3
3 6 7 
8 9 6 10
o/p:14
*/
fn(int i,int j,vector<vector<int>>triangle,int m)
{
    if(i==m-1)return triangle[m-1][j];
    int down =triangle[i][j]+fn(i+1,j,triangle,m);
    int downdiagonal=triangle[i][j]+fn(i+1,j+1,triangle,m);
    return min(down,downdiagonal);
}   





// 1d dp
/*
You are given an integer array nums. You are initially positioned at the
array's first index, and each element in the array represents your maximum
jump length at that position.
Return true if you can reach the last index, or false otherwise.
Input: nums = [2,3,1,1,4]
Output: true
*/
bool func(int ind,vector<int>nums,int n)
{
    if(ind==n-1)
    {
        return true;
    }
    if(nums[ind]==0){return false;}
    for(int i=1;i<=nums[i];i++)
    {
        if(i+ind<=n-1&&func(i+ind,nums,n))
        {
            return true;
        }
    }
    return false;
    
}
bool jumpgame(vector<int>nums)
{
    int n=nums.size();
    return func(0,nums,n);

}

//jump game 2
/*
You are given a 0-indexed array of integers nums of length n. 
You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from
index i. In other words, if you are at nums[i], you can jump to any 
nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases 
are generated such that you can reach nums[n - 1].
*/
int solve(int ind,vector<int>&nums,vector<int>&dp)
{
    if(ind==nums.size()-1)
    {
        return 0;
    }
    int mini = 1e9;
    if(dp[ind]!=-1){return dp[ind];}    
    for(int i=1;i<=nums[ind];i++)
    {
        if(i+ind<=nums.size()-1)
        {
            mini=min(mini,1+solve(ind+i,nums,dp));
        }

    }    
    return dp[ind]=mini;
}
int jumpgame2(vector<int>&nums)
{
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return solve(0,nums,dp);
}




//vacations/house robbers
int solve1(int ind,int prev,vector<vector<int>>nums,vector<vector<int>>dp)
{
    if(ind==0)
    {
        int ans=0;
        for(int i=0;i<3;i++)
        {
            if(i!=prev)
                {ans=max(ans,nums[0][i]);}
        }
        return ans;
    }
    if(dp[ind][prev]!=-1){return dp[ind][prev];}
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=prev)
        {
            maxi=max(maxi,nums[ind][i]+solve1(ind-1,i,nums,dp));
        }
    }
    return dp[ind][prev]=maxi;

}
int vacations(vector<vector<int>>&nums,int n)
{

    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    return solve1(n-1,3,nums,dp);
}









int main()
{
    // input grid sized m*n
   // int m,n;
   /* cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }*/
   // cout<<countpathstab(m-1,n-1)<<endl;
   // cout<<countpaths(m-1,n-1)<<endl;
   // cout<< uniquepathtab(m-1,n-1,grid); 
   //cout<<minimumpathsum(m-1,n-1,grid);
   
   /*cin>>m;
   vector<vector<int>>tri(m);
   for(int i=0;i<m;i++)
   {
        for(int j=0;j<i+1;j++)
        {
            int t;
            cin>>t;
            tri[i].push_back(t);
        }
   }
   cout<<fn(0,0,tri,m);
   */
    /*
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<jumpgame2(nums);
    */
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }
    cout<< vacations(nums,n);

}