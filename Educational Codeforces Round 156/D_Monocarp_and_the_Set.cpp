#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long

ll power(ll a, ll b)
{
    ll val = a;
 
    ll ans = 1;
 
    ll temp = b;
    while (temp != 0)
    {
        if (temp % 2)
        {
            ans *= (val);
            ans %= mod;
        }
        val *= val;
        val %= mod;
        temp /= 2;
    }
 
    return ans;
}

ll sum(ll x, ll y)
{
 
    return (x % mod + y % mod) % mod;
}

ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}

ll subs(ll x, ll y)
{
    return (x % mod - y % mod + mod) % mod;
}

// ll fact[3000005];
// ll inver[3000005];

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll ans=1;
    for(int i=1; i<n-1; i++){
        if(s[i]=='?'){
            ans=mul(ans,i);
        }
    }

    if(s[0]=='?'){
        cout<<"0"<<endl;
    }else{
        cout<<ans<<endl;
    }

    while (m--)
    {
        ll pos;
        char ch;
        cin>>pos>>ch;
 
        pos--;
 
        if(s[pos]=='?' && pos!=0){
            ans=mul(ans,power(pos,mod-2));
        }
        
 
        s[pos]=ch;
 
        if(s[pos]=='?' && pos!=0){
            ans=mul(ans,pos);
        }
 
        if(s[0]=='?'){
            cout<<"0"<<endl;
            continue;
        }
 
        cout<<ans<<endl;
    }
    return 0;
}