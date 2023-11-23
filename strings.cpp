#include <bits/stdc++.h>
using namespace std;
int main()
{
 string str2;
 string str_rev;
  getline(cin,str2);
 cout<<str2<<endl;

 for(int i=str2.size()-1;i>=0;--i)  //reversing a string
 {
 	str_rev.push_back(str2[i]);
 }
cout<<str_rev<<endl;
//checking if a palindrome
if(str_rev==str2){ cout<<"yes its a palindrome";}
else{cout<<"not a palindrome";}

}