#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll m,k,a1,ak;
        cin >> m >> k >> a1 >> ak;
        ll ans;
        if(a1>=m ){
            ans = 0;
        }else{
            if(ak==0 && a1==0){
                if(k==0){
                    ans = m;
                }else{
                    ans = (m/k) + (m%k);
                }
            }else if(ak==0){
                if(m-a1>=k){
                    ll rem = m-a1;
                    ans = (rem%k) + (rem/k);
                }else{
                    ans = 1;
                }
            }else if(a1==0){
                if(m-k>=0){
                    ll rem = m/k;
                    if(rem<=ak){
                        ll rem2 = rem*k;
                        ans = (m-rem2);
                        
                    }else{
                        ll rem2 = m-(ak*k);
                        ans = (rem2/k) + (rem2%k);
                    }
                }else{
                    ans = m;
                }
            }else{
                ll rem = m/k;
                if(rem <= ak){
                    ll rem2 = m-(rem*k);
                    if(rem2<=a1){
                        ans=0;
                    }else{
                        if(rem2-a1>=k){
                            ll rem3 = rem2-a1;
                            ans = (rem3/k) + (rem3%k);
                        }else{
                            ans = rem2-a1;
                        }
                    }
                }else{
                    ll rem2 = m-(ak*k);
                    if(rem2 <= a1){
                        ans=0;
                    }else{
                        ll rem4 = rem2/k;
                        ll rem5 = rem2%k;

                        if(rem2-a1>=k){
                            ll rem3 = rem2-a1;
                            ans = (rem3/k) + (rem3%k);
                        }else{
                            ans = 1;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     int m, k, a1, ak; 
//     cin >> m >> k >> a1 >> ak;
//     cout << (m/k - min(m/k, ak + (max((a1-(m%k)),0) / k))) + max(0,(m%k)-a1) << endl;
//   }
// }