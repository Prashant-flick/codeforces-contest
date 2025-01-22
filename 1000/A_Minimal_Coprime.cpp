#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int l,r;
    cin >> l >> r;
    if(l==1 && r==1){
        cout << 1 << endl;
        return;
    }
    cout << r-l << endl;
}

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}