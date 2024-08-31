#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        int ans = r-l+1;
        if(l%2==0){
            ans--;
        }
        int i=0;
        int cnt=0;
        while(i<ans){
            if(i+3<=ans){
                cnt++;
            }
            i+=4;
        }
        cout << cnt << endl; 
    }
}