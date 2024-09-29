#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==1){
            cout << n << endl;
            continue;
        }
        
        int ans=0;
        while(n>0){
            if(n>=k){
                int res=1;
                while(n>=res){
                    res*=k;
                }
                res=res/k;
                n-=res;
                ans++;
            }else{
                ans+=n;
                n=0;
            }
        }
        cout << ans << endl;
    }
}