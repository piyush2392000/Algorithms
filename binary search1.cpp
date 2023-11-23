#include <bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int m,int e)
{
    int low=0;
    int high=m-1;
    
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(a[mid]=e) return mid;
        else if(a[mid]<e) low=mid+1;
        else if(a[mid]>e) high=mid-1;
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
	int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int e;
    cin>>e;
   cout<<binarysearch(arr,n-1,e);
   
    
}
