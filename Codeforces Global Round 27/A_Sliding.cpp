#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n,m,r,c;
        cin >> n >> m >> r >> c;
        int ans = (m-c);
        ans += ((n-r)*(1LL+(m-1))) + 0LL + ((n-r)*(m-1LL));
        cout << ans << endl;
    }
}