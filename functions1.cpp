#include <bits/stdc++.h>
using namespace std;

void printhello(){
    cout<< "Hello";
}

int digitsum(int n){
    int digitsum = 0;
    while(n){
    digitsum=digitsum + n%10;
    n=n/10;
    }
    return digitsum;
}


int main()
{
   int a,b;
   cin >> a >> b;
   cout << digitsum(a)+digitsum(b);
    return 0;
    
}