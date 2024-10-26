#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

int pow(int a, int b){
    if(b==0)return 1;
    int res=a;
    for(int i=1; i<b; i++){
        res = (res*a)%mod;
    }
    return res;
}

signed main(){
    int pow2[510];
    pow2[0]=1LL;
    for(int i=1; i<=510; i++){
        pow2[i] = (pow2[i-1]*2LL)%mod;
    }

    // int fact[510];
    // fact[0]=fact[1]=1;
    // for(int i=2; i<=510; i++){
    //     fact[i] = (fact[i-1]*i*1LL)%mod;
    // }

    int n,m;
    cin >> n >> m;
    int sum=pow2[m/2-1];
    int ans = pow(sum, n);
    cout << ans << endl;

    int rem = m/2;
    int i=1;
    while(rem>0){
        if(i<n){
            int res = pow2[(m/2)-i-1];
            int res2 = (pow2[m/2-1]*(n-(i+1))*1LL)%mod;
            int res3 = (pow2[(m/2)-1]*i*1LL)%mod;
            int res4 = (res*res3*1LL)%mod;
            int a = i==1?(m-1) : m-i;
            if(i==1){
                res4 = (res4*a*1LL)%mod;
            }else{
                res4 = (res4*((a*(a+1))/2)*1LL)%mod;
            }
            ans = (ans+res2+res4+0LL)%mod;
            rem-=2;
            i++;
        }else{
            break;
        }
    }
    cout << ans << endl;
}