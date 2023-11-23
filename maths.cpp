#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int countnoofprimes(int n)
{
	int count=0;
	for(int i=2;i<n;i++)
	{
		if(isprime(i))
		{
			count++;
		}
	}
	return count;
}

//sieve of erastosthenes
void sieveprime(int n)
{
    int prime[100]={0};
    for(int i=2;i<n;i++)
    {
    	if(prime[i]==0)
    	{
    		for(int j=i*i;j<n;j=j+=i)
    		{
    			prime[j]=1;
    		}
    	}
    }

    for(int i=2;i<n;i++)
    {
    	if(prime[i]==0)
    	{
    		cout<<i<<endl;
    	}

    }
}

void printbinary(int num)
{
	for(int i=10;i>=0;--i)
	{
		cout<<((num>>i)&1);
	}
	cout<<end;
}

void checksetbit(int num,int i)//check i th bit for set unset
{
	if((num&(1<<i))!=0)
	{
		cout<<"set bit";
	}
	else
	{
		cout<<"unset bit/not set bit";
	}
}

int set_bit(int num,int i)
{
	int b=(num|(1<<i));
	return b;
}

int unset_bit(int num,int i)
{
	int b=(num & ~(1<<i));  // ~ used to invert binary nos
	return b;
}

int toggle_bit(int num,int i)  // invert only ith bit
{
	int b=(num^(1<<i));
	return b;
}
//no of set bits or use directly fn __builtin_popcount(num);
int bitcount(int num)
{
	int count=0;
	for(int i=31;i>=0;--i)
	{
		if((num&(1<<i))!=0)
	    {
		   count++;
	    }
	}
	return count;
}
void swappingnos(int a ,int b)
{
	a=a^b;
	b=b^a;  // b=b^(a^b)=a
	a=a^b;  // a=a^(b^a)=b
}
vector<vector<int>> subsets(vector<int>& nums) 
{
        int n=nums.size();
        int subset_ct=(1<<n);
        vector<vector<int>>ans;
        for(int mask=0;mask<subset_ct;++mask)
        {
            vector<int>subset;
            for(int i=0;i<n;++i)
            {
                if((mask&(1<<i))!=0)
                {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
}

int main()
{
	printbinary(5);
	   
   
    return 0;
}