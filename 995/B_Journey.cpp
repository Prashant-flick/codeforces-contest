#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        int tot = a+b+c;
        int d = n/tot;
        int e = n%tot;
        int ans = d*3;
        if(e==0){
            cout << ans << endl;
        }else{
            e-=a;
            ans++;
            if(e<=0){
                cout << ans << endl;
            }else{
                e-=b;
                ans++;
                if(e<=0){
                    cout << ans << endl;
                }else{
                    cout << ans+1 << endl;
                }
            }
        }
    }
}