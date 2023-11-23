#include <bits/stdc++.h>
using namespace std;


//example:cout<<balanced_parenthesis("{{([])}}");
bool balanced_parenthesis(string s)
{
	stack<char>st;
	unordered_map<char,int>symbols={{'{',-1},{'[',-2},{'(',-3},{'}',1},{']',2},{')',3}};
	for(char bracket:s)
	{
		if(symbols[bracket]<0)
		{
			st.push(bracket);
		}
		else // if closing bracket or symbols[bracket]>0
		{
			if(st.empty())return false;
			char top=st.top();
			st.pop();
			if(symbols[top]+symbols[bracket]!=0)return false;
		}
	}
	if(st.empty())return true;
	return false;
} 

vector<int> next_greater_element1(vector<int>v)
{
	stack<int>st;
	vector<int>nge(v.size());
	for(int i=0;i<v.size();i++)
	{
		while(!st.empty()&&v[i]>v[st.top()])
		{
			nge[st.top()]=i;
		}
		st.push(i);
	}

	while(!st.empty())
	{
		nge[st.top()]=-1;
		st.pop();
	}
	return nge;

}

vector<int> next_greater_element2(vector<int>arr)
{
	stack<int>s;
	vector<int>v;
	for(int i=arr.size()-1;i>=0;i--)
	{
		if(s.empty())
		{
			v.push_back(-1);
		}
		else if(!s.empty()&&s.top()>arr[i])
		{
			v.push_back(s.top());
		}
		else if(!s.empty()&&s.top()<arr[i])
		{
			while(!s.empty()&&s.top()<arr[i])
			{
               s.pop();
			}
			if(s.empty())
			{
				v.push_back(-1);
			}
			else if(s.top()>arr[i])
			{
				v.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	reverse(v.begin(),v.end());
	return v;
}


int main()
{
	/*stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}*/

	/*queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}*/

	vector<int>arr({1,3,2,4});
	vector<int>v;
	v=next_greater_element2(arr);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}

	
	return 0;
}

