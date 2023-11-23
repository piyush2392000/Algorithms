#include <bits/stdc++.h>
using namespace std;

int main(){
	int  T;
	cin >> T;
	while(T--)
	{
		int N;
		cin>>N;
		for(int i=1;i<=N;i++)
	     {
	    for(int j=1;j<=i;j++){cout<<'*';}
	    for(int j=2*(N-i);j<=1;j--){cout<<'#';} 
		 cout<<endl;
	     }
	}     
}
