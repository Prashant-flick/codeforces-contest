#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int l,r,d,u;
        cin >> l >> r >> d >> u;
        if(l==r && r==d && d==u){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}