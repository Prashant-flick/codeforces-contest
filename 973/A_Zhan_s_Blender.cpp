#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x, y;
        cin >> x >> y;
        int temp = min(x,y);
        cout << n/temp+(n%temp==0?0:1) << endl;
    }
}