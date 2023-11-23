#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
	if(n==0)
	{
		return 0;
	}

	int prevsum=sum(n-1);
	return n+prevsum;
}

int pow(int n,int p)
{
	if(p==0)
	{
		return 1;
	}
	int prevpow=pow(n,p-1);
	return (n*prevpow);
}

int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	int prevfac=factorial(n-1);
	return n*prevfac;
}

int fib(int n)
{
	if(n==0||n==1)
	{
		return n;
	}
	return fib(n-1)+fib(n-2);
}

//check if array is sorted or not through recursion
bool sorted(int arr[],int n)
{
    if(n==1)
    {
    	return true;
    }

	bool restarray =sorted(arr+1,n-1);
	return (arr[1]>arr[0] && restarray);
	
}
// print number till n in decreasing order
void dec(int n)
{
	if(n==0)
	{
		return;
	}
	cout<<n<<endl;
	dec(n-1);
}
// print number till n in increasing order
void inc(int n)
{
	if(n==0)
	{
		return;
	}
	inc(n-1);
	cout<<n<<endl;
	
}
// first occurrance of a element in a array
int firstocc(int arr[],int n,int i,int key)
{
	if(i==n)
	{
		return -1;
	}

	if(arr[i]==key)
	{
		return i;
	}
	return firstocc(arr,n,i+1,key);
}
// last occurrance of a element in a array
int lastocc(int arr[],int n,int i,int key)
{
	if(i==n)
	{
		return -1;
	}
	return lastocc(arr,n,i+1,key);
	if(arr[i]==key)
	{
		return i;
	}

}

//reversing a string
void reverse(string s)
{
	if(s.length()==0)
	{
		return;
	}

	string ros=s.substr(1);
	reverse(ros);
	cout<<s[0];
}
// replacing a "pi" in string with "3.14"  example:"pipipippppxxxppi
void replacepi(string s)
{
	if(s.length()==0)
	{
		return;
	}
	 if(s[0]=='p'&&s[1]=='i')
	 {
	 	cout<<3.14;
	 	string ros=s.substr(2);
	 	replacepi(ros);
	 }
	 else
	 {
	 	cout<<s[0];
	 	replacepi(s.substr(1));
	 }
}
// towerofhanoi(4,'A','B','C');
void towerofhanoi(int n,char src,char dest,char help)
{
	if(n==0)
	{
		return;
	}
	towerofhanoi(n-1,src,help,dest);
	cout<<"move from "<<src<<" to "<<dest<<endl;
	towerofhanoi(n-1,help,dest,src);
}
// cout<<removedup("aaaaabbbbeeeedddd");
string removedup(string s)
{
	if(s.length()==0)
	{
		return "";
	}
	char a=s[0];
	string ans =removedup(s.substr(1));
	if(a==ans[0])
	{
		return ans;
	}
	return a+ans;
}

//move all x to the end ex:cout<<movetoend("xxxxxabxxxde");
string movetoend(string s)
{
	if(s.length()==0)
	{
		return "";
	}
	char a=s[0];
	string ans=movetoend(s.substr(1));
	if(a=='x')
	{
		return ans+a;
	}
	return a+ans;
}
// permutations of a string
void permutations(string s,string ans)
{
	if(s.length()==0)
	{
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		string ros=s.substr(0,i)+s.substr(i+1);
		permutations(s,ans+ch);
	}
}
// count no paths from index s to e
int countways(int s,int e)
{
	if(s==e)
	{
		return 1;
	}
	if(s>e)
	{
		return 0;
	}
    int count=0;
    for(int i=1;i<4;i++)
    {
	  count+=countways(s+i,e);
	  
    }
    return count;
}

int countpath(int n,int i,int j)
{
    if(i==n-1&&j==n-1)
    {
       return 1;
    }
    if(i>n||j>n)
    {
    	return 0;
    }

    return countpath(n,i+1,j)+countpath(n,i,j+1);
}

int tilingways(int n)
{

	if(n==1)
	{
		return 1;
	}
	if(n==0)
	{
		return 0;
	}

	return tilingways(n-1)+tilingways(n-2);
}

//friends pairing problem
int pairing(int n)
{
	if(n==0||n==1||n==2)
	{
		return n;
	}
	return pairing(n-1)+pairing(n-2)*(n-1);
}

//knapsack problem 
// a sack of definite capacity is given select goods 
//to put in sack such that maximum value of goods can 
//be put in sack
/* example 
    int value[]={100,50,150};
	int weight[]={10,20,30};
	int W=50;

	cout<<knapsack(value,weight,3,W);*/
int knapsack(int value[],int weight[],int n,int W )
{
	if(n==0||W==0)
	{
		return 0;
	}

	if(weight[n-1]>W)
	{
		return knapsack(value,weight,n-1,W);
	}
	return max(knapsack(value,weight,n-1,W-weight[n])+value[n-1],knapsack(value,weight,n-1,W));
    

}



int main()
{
	return 0;
}