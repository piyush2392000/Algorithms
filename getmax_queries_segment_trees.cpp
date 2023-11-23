#include <bits/stdc++.h>
using namespace std;
int arr[10001],segtree[40004];
int buildst(int si,int ss,int se)
{
    if(se==ss){return segtree[si]=arr[ss];}
    int mid=(se+ss)/2;
    segtree[si]=max(buildst(2*si+1,ss,mid),buildst(2*si+2,mid+1,se));
    return segtree[si];
}
int getmax(int qs,int qe,int ss,int se,int si)
{
    if(qs<=ss&&qe>=se)
        {return segtree[si];}
    if(se<qs||ss>qe){return INT_MIN;}
    int mid=(ss+se)/2;
    return max(getmax(qs,qe,ss,mid,2*si+1),getmax(qs,qe,mid+1,se,2*si+2));
}

int main()
{
    int n;
    cin>>n;
    int qs,qe;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    buildst(0,0,n-1);
    int q;
    cin>>q;
    while(q--)
    {
        
        cin>>qs>>qe;
        cout<<getmax(qs,qe,0,n-1,0)<<endl;
    }
    return 0;
}
