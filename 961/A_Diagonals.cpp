#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t=1;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==0){
            cout << 0 << endl;
        }else{
            k-=n;
            int ans=1;
            int i=n-1;
            for(; i>=1; i--){
                if(k>=i){
                    k-=i;
                    ans++;
                }else{
                    break;
                }
                if(k>=i){
                    k-=i;
                    ans++;
                }else{
                    break;
                }
            }
            if(k>0 && i>0){
                ans++;
            }
            cout << ans << endl;
        }
    }
}