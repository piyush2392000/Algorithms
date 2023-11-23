#include <bits/stdc++.h>
using namespace std;
bool subsetsum(int nums[],int n,int sum)
{
        bool t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    t[i][j]=false;
                }
			    if(j==0)
                {
                    t[i][j]=true;
                }

            }
        }

          for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j]=(t[i-1][j-nums[i-1]]||t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }

            }
        }

        return t[n][sum];

}

bool equal_sum_partition(int arr,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if(sum%2!=0)
	{
		return false;
	}
	else if(sum%2==0)
	{
		return subsetsum(arr,n,sum/2);
	}
}


int countsubsetwithsum(int nums[],int n,sum)
{
	 int t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    t[i][j]=0;
                }
			    if(j==0)
                {
                    t[i][j]=1;
                }

            }
        }

          for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j]=(t[i-1][j-nums[i-1]]+t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }

            }
        }

        return t[n][sum];
}
int minimum_subset_sum_difference(int nums[],int n)
{
	
}
int main()
{
	int n=5;
	int arr[n]={2,3,7,8,10};
	cout<<subsetsum(arr,n,11);

	return 0;
}