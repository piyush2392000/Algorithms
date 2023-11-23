#include <bits/stdc++.h>
using namespace std;
// subset
void f(int ind,vector<int>&a,vector<vector<int>>&ds,vector<int>&v)
{
	if(ind==v.size())
	{
		ds.push_back(a);
		return ;
	}
    a.push_back(v[ind]);
    f(ind+1,a,ds,v);
    a.pop_back();
    f(ind+1,a,ds,v);

}
vector<vector<int>> subset(vector<int>v)
{
	vector<vector<int>>ds;
	vector<int>a;
	f(0,a,ds,v);
	return ds;
}

// subset with a target sum k
void fn(int ind,vector<int>&a,vector<vector<int>>&ds,vector<int>&v,int sum,int k)
{
	if(ind==v.size())
	{
		if(sum==k)
		{
		   ds.push_back(a);
	    }
		return ;
	}
    a.push_back(v[ind]);
    sum=sum+v[ind];
    fn(ind+1,a,ds,v,sum,k);
    a.pop_back();
    sum=sum-v[ind];
    fn(ind+1,a,ds,v,sum,k);

}
vector<vector<int>>subsetsum(vector<int>&v,int k)
{
    vector<vector<int>>ds;
    vector<int>a;
    fn(0,a,ds,v,0,k);
    return ds;
}

//  combination sum 1
void solve(int ind,int target,vector<int>&a,vector<vector<int>>&ds,vector<int>&v)
{
	if(ind==v.size())
	{
		if(target==0)
		{
			ds.push_back(a);
		}
		return;
	}
	if(v[ind]<=target)
	{
		a.push_back(v[ind]);
		solve(ind,target-v[ind],a,ds,v);
		a.pop_back();
	}
	solve(ind+1,target,a,ds,v);
}
vector<vector<int>>combinationsum(vector<int>v,int target)
{
	int n=v.size();
	vector<vector<int>>ds;
	vector<int>a;
	solve(0,target,a,ds,v);
	return ds;

}


// combination sum 2
void solve1(int ind,int target,vector<int>a,vector<vector<int>>ds,vector<int>v)
{
	if(target==0)
	{
		ds.push_back(a);
	}
	return;

	for(int i=ind;i<v.size();i++)
	{
		if(i>ind&&v[i]==v[i-1]){continue;}
		if(v[i]>target)break;  // as array is sorted
        a.push_back(v[i]);
		solve1(i+1,target-v[i],a,ds,v);
		a.pop_back();
	}
	

}
vector<vector<int>> combinationsum2(vector<int>v,int target)
{
	sort(v.begin(),v.end());
	vector<int>a;
	vector<vector<int>>ds;
	solve1(0,target,a,ds,v);
	return ds;
}


// subset sum 1
void func(int ind,int sum,vector<int>&v,vector<int>&ans)
{
	if(ind==v.size())
	{
		ans.push_back(sum);
	}

	func(ind+1,sum+v[ind],v,ans);
	func(ind+1,sum,v,ans);
}

vector<int>subsetsum1(vector<int>v)
{
	vector<int>ans;
	func(0,0,v,ans);
	return ans;
}

// subset sum 2
//  i/p:nums=[1,2,2]
//  o/p:[[],[1],[1,2],[1,2,2],[2],[2,2]]
// cannot have duplicate subsets
void func1(int ind,vector<int>&a,vector<vector<int>>&ans,vector<int>&v)
{
	ans.push_back(a);
	for(int i=ind;i<v.size();i++)
	{
		if(i!=ind&&v[i]==v[i-1]){continue;}
		a.push_back(v[i]);
		func1(i+1,a,ans,v);
		a.pop_back();
	}
}
vector<vector<int>> subsetsum2(vector<int>&v)
{
    vector<int>a;
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    func1(0,a,ans,v);
    return ans;
}

// letter tiles possiblitity
// Input: tiles = "AAB"
// Output: 8("A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA")  


void func1(vector<char>&temp,set<vector<char>>&ans,string &tiles,vector<int>&flag)
    {
        if(temp.size()>=1)
        {
            ans.insert(temp);
            
        }

        for(int i=0;i<tiles.size();i++)
        {
            if(flag[i]!=1){
            flag[i]=1;
            temp.push_back(tiles[i]);
            func1(temp,ans,tiles,flag);
            temp.pop_back();
            flag[i]=0;}

        }
        
    }
   
    int numTilePossibilities(string tiles) {
        vector<char>temp;
        set<vector<char>>ans;
        vector<int>flag(tiles.size(),0);
        func1(temp,ans,tiles,flag);
        return ans.size();

        
    }


int main()
{   
    int n;
    cin>>n;
    vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	//int k;
	//cin>>k;
	vector<vector<int>>ans=subsetsum2(v);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}