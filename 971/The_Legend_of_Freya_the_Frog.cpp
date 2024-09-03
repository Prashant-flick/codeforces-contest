#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int x,y, k;
        cin >> x >> y >> k;
        int a = (x/k+(x%k!=0?1:0));
        int b = (y/k+(y%k!=0?1:0));
        if(a>b){
            cout << max(a,b)*2 -1 << endl;
        }else{
            cout << max(a,b)*2<< endl;
        }
    }
}