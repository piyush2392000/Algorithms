#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x=0;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	for(int i=0;i<n;i++)
	{
		if(arr[i]==3){
			for(int j=i;j<n;j++)
			{
				arr[j]=arr[j+1];
			}
			break;
		}

			
	}
	arr[n-1]=0;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	   
   
    return 0;
}
