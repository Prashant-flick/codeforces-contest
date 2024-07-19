#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int MAXN=1e6+1;
const int INF=1e9+1;
const int MOD=1e9+7;
 
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    int p=31,mod=1e9+9;
    vector<int>power(n+1);
    power[0]=1;
    for (int i=1;i<n;i++) {
        power[i]=power[i-1]*p;
        power[i]%=mod;
    }
    vector<int>pref(n+1,0);
    for (int i=1;i<=n;i++) {
        pref[i]=pref[i-1]+(s[i]-'a'+1)*power[i-1];
        pref[i]%=mod;
    }
    vector<int>possible;
    for (int i=1;i<n;i++) {
        int forward_h=pref[i];
        int backward_h=(pref[n]-pref[n-i]+mod)%mod;
        forward_h*=power[n-i];
        forward_h%=mod;
        //cout<<forward_h<<" "<<backward_h<<"\n";
        if (forward_h==backward_h) {
            possible.push_back(i);
        }
    }
    //for (int i=0;i<possible.size();i++) {
        //cout<<possible[i]<<" ";
    //}
    sort(possible.begin(),possible.end());
    int l=0,r=possible.size()-1;
    int ans=-1;