#include <bits/stdc++.h>
using namespace std;
int arr[100001],stree[400004];

int constructST(int ss,int se,int si)
{
	if(ss=se)
	{
		stree[si]=arr[ss];
        return arr[ss];
	}
	int mid=(ss+se)/2;
	stree[si]=constructST(ss,mid,2*si+1)+constructST(mid+1,se,2*si+2);
	return stree[si];
}
int getsum(int qs,int qe,int ss,int se,int si)
{  
      if(se<qs||ss>qe){return 0;}
      if(qs<=ss&&qe>=se){return stree[si];}
      int mid=(ss+se)/2;
      return getsum(qs,qe,ss,mid,2*si+1)+getsum(qs,qe,mid+1,se,2*si+2);
}

int main()
{
	int n,q,l,r;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	constructST(0,n-1,0);
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<getsum(l,r,0,n-1,0);

	}
	
	
   
    return 0;
}