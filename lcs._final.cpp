#include <bits/stdc++.h>
using namespace std;
//length of lcs
int f(int i,int j,string s,string t,vector<vector<int>>&dp)
{
	if(i<0||j<0){return 0;}
	if(dp[i][j]!=-1){return dp[i][j];}
	if(s[i]==t[j]){return dp[i][j]=1+f(i-1,j-1,s,t,dp);}
	else
	{
       dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
	}
	return dp[i][j];
    
}
int lcs(string s,string t)
{
	int n=s.size();
	int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	return f(n-1,m-1,s,t,dp);
}



//printing lcs
string printlcs(string s,string t)
{
	int n=s.size();
	int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	for(int i=0;i<n+1;i++)
    {
    	for(int j=0;j<m+1;j++)
    	{
    	   if(i==0||j==0){dp[i][j]=0;}
    	}
    }
    for(int i=1;i<n+1;i++)
    {
    	for(int j=1;j<m+1;j++)
    	{
    	   if(s[i-1]==t[j-1]){dp[i][j]=1+dp[i-1][j-1];}
    	   else
    	   {
    	   	  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    	   }
    	}
    }
    int i=n;
    int j=m;
    string ans="";
    while(i>0&&j>0)
    {
    	if(s[i-1]==t[j-1])
    	{
    		ans.push_back(s[i-1]);
    		i--;j--;
    	}
    	else
    	{
    		if(dp[i-1][j]>dp[i][j-1]){i--;}
    		else{j--;}
    	}

    }
    reverse(ans.begin(),ans.end());
    return ans;
}






// longest common substring
int longest_common_substring(string s,string t)
{
	int n=s.size();
	int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	for(int i=0;i<n+1;i++)
    {
    	for(int j=0;j<m+1;j++)
    	{
    	   if(i==0||j==0){dp[i][j]=0;}
    	}
    }
    for(int i=1;i<n+1;i++)
    {
    	for(int j=1;j<m+1;j++)
    	{
    	   if(s[i-1]==t[j-1]){dp[i][j]=1+dp[i-1][j-1];}
    	   else
    	   {
    	   	  dp[i][j]=0;
    	   }
    	}
    }
    int maxi=INT_MIN;
    int start;
    int end;
    for(int i=0;i<n+1;i++)
    {
    	for(int j=0;j<m+1;j++)
    	{
           if(dp[i][j]>maxi)
           {
               maxi=dp[i][j];
               start=i;
               end=j;
           }
           //maxi=max(maxi,dp[i][j]);
    	}
    }

    string ans="";
    while(dp[start][end]>=1)
    {
        ans=ans+s[start-1];
        start--;
        end--;
    }
    // retrun ans;    // this returns the longest common substring
    return maxi;
}
// shortest commmon supersequence
// i/p  s=geek, t=eke
// o/p  ans:(5)geeke

// intution merge them removing subsequence
int scs(string s,string t)
{
	int n=s.size();
	int m=t.size();
	return m+n-lcs(s,t);
}


// printing shortest common supersequence
string shortest_common_supersequence(string s,string t)
{
	int n=s.size();
	int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	for(int i=0;i<n+1;i++)
    {
    	for(int j=0;j<m+1;j++)
    	{
    	   if(i==0||j==0){dp[i][j]=0;}
    	}
    }
    for(int i=1;i<n+1;i++)
    {
    	for(int j=1;j<m+1;j++)
    	{
    	   if(s[i-1]==t[j-1]){dp[i][j]=1+dp[i-1][j-1];}
    	   else
    	   {
    	   	  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    	   }
    	}
    }
    int i=n;
    int j=m;
    string ans="";
    while(i>0&&j>0)
    {
    	if(s[i-1]==t[j-1])
    	{
    		ans.push_back(s[i-1]);
    		i--;j--;
    	}
    	else
    	{
    		if(dp[i-1][j]>dp[i][j-1]){ans.push_back(s[i-1]);i--;}
    		else{ans.push_back(t[j-1]);j--;}
    	}

    }
    while(i>0)
    {
    	ans.push_back(s[i-1]);
    	i--;
    }
    while(j>0)
    {
    	ans.push_back(t[j-1]);
    	j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}





// insertion to make s to t
int no_of_insertion(string s,string t)
{
	int n=s.size();
	return n-lcs(s,t);
}
// deletion to make s to t
int no_of_deletion(string s,string t)
{
	int m=t.size();
	return m-lcs(s,t);
}




//longest palindromic subsequence
//i/p:agbcba
//o/p:5(abcba)
int longest_palindromic_subseq(string s)
{
	string t=s;
	reverse(t.begin(),t.end());
	return lcs(s,t);

	// min no of insertion to make it a palindrome

}

string print_longest_palindromic_subseq(string s)
{
	string t=s;
	reverse(t.begin(),t.end());
    return printlcs(s,t);

}



// longest palindromic substring
string longest_palindromic_substring(string s)
{
	int n=s.size()-1;
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	
	for(int i=0;i<=n;i++)
	{
		dp[i][i]=1;		
	}
	for(int i=0;i<=n;i++)
	{
		if(s[i]=s[i+1])
		{
			dp[i][i+1]=1;
		}
	}
	for(int start=0;start<=n-2;start++)
	{
		for(int end=2;end<=n;end++)
		{
			if(s[start]==s[end]&&dp[start+1][end-1]==1)
			{
				dp[start][end]=1;
			}
		}
	}
	maxsize=0;
	int s;
	int e;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j-i+1>maxsize&&dp[i][j]==1&&i<j)
			{
				maxsize=j-i+1;
				s=i;
				e=j
			}
		}
	}
	string ans="";
	for(int i=s;i<=e;i++)
	{
		ans=ans+s[i];
	}
	return ans;

	//count of palindromic substring
	
	/*
	        int cnt=0;
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					if(dp[i][j]==1)
					{
						cnt++;
					}
				}
			}
			return cnt;
    */
}





int main()
{
	string s;
	string t;
	cin>>s;
	cin>>t;
//	cout<<lcs(s,t);
//	cout<<printlcs(s,t);
//	cout<<longest_common_substring(s,t);
//  cout<<scs(s,t);	
//  cout<<shortest_common_supersequence(s,t);
//  cout<<longest_palindromic_subseq(s);
//  cout<<print_longest_palindromic_subseq(s);
//	cout<<longest_palindromic_substring(s);

}