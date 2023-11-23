#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
    cin >> n ;
    int arr[n];
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
  int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
        a[i]=mx;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}