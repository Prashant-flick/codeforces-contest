#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        int cnt = r-l+1;
        if(cnt==1){
            cout << 1 << endl;
            continue;
        }
        int i=1;
        while(true){
            int temp = (i*(i+1))/2;
            if(temp>=cnt)break;
            i++;
        }
        cout << i << endl;
    }
}