#include <bits/stdc++.h>
using namespace std;




bool isPalindrome(int x) {             //optimized soln
        if(x<0) return false;
        string s=to_string(x);
        for(int i=0;i<s.size()/2+1;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }

/* bool isPalindrome(int x) {                      //my soln
        int originalx=x;
        unsigned int reverse=0;
        while(x>0)
        {
            reverse=reverse*10*1LL+x%10;
            x=x/10;
        }
        if(reverse==originalx)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    } */    
int main()
{
    int x;
    cin>>x;
   cout<< isPalindrome(x);
    return 0;
}
