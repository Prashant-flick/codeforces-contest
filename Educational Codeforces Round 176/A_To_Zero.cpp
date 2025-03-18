#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int ans=0;
        if(n%2){
            n-=((k-1)/2)*2+1;
            ans=1;
        }
        if(k%2)k--;
        ans+=(n/k)+(n%k>=1?1:0);
        cout << ans << endl;
    }
}