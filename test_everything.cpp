#include <bits/stdc++.h>
using namespace std;

int main()
{
     char a[8];
     cin.getline(a,8);
     cout<<a<<endl;
     string c;
     cin>>c;
     cout<<c<<endl;
     stringstream s(a);
     unordered_map<string,int>mp;
     string word;
     while(s>>word)
     {
        mp[word]++;
     }
     for(auto it:mp)
     {
        cout<<it.first<<" "<<it.second<<endl;
     }
}