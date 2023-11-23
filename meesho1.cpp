#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int target;
	cin>>target;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[nums[i]]=i;
	}
	int i=0;
	int j=n-1;
	sort(nums.begin(),nums.end());
	vector<vector<int>>ans;
	while(j>i)
	{
		if(abs(nums[i]-nums[j])+abs(nums[i]+nums[j])==target)
		{
			ans.push_back({mp[nums[i]],mp[nums[j]]});
			i++;j--;
			continue;
		}
		else if(abs(nums[i]-nums[j])+abs(nums[i]+nums[j])<target)
		{
            i++;
		}
		else
		{
			j--;
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
}