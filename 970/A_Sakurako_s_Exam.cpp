#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if((b%2==0 && a%2==0) || (b%2==1 && a%2==0 && a>=2)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}