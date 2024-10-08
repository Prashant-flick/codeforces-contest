#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        ll a,b;
        cin >> a >> b;
        ll ans=b;
        if(b%a==0){
            cout << 1LL*b*(b/a) << endl;
        }else{
            ll res = lcm(a,b);
            cout << res << endl;
        }
    }
    
    return 0;
}