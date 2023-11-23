#include <bits/stdc++.h>
using namespace std;
int lis_binary_search(vector<int>&nums)
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
            auto ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind]=nums[i];
        }
    }
    return len;
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
}