#include <bits/stdc++.h>
using namespace std;
int main()
{
	/*string s;
	cin>>s;
	int dec=0;
	//reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
	{
		dec=dec+((s[i]-'0')*pow(2,i));
	}
	*/
	
	uint32_t n;
	cin>>n;
	int i;
	cin>>i;
	// turn on ith bit
	int mask=1<<i;   // or with mask
	// turn off ith bit
	int mask2=!(1<<i); // ans with mask
	// toggle ith bit 
	int mask3=1<<i; //xor with mask
	// check ith bit
	int mask4=1<<i;
	bool res;
	res=n&mask4==0?false:true;
	cout<<res;
}