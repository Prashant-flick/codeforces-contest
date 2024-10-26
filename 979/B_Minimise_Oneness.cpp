#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = "1";
        for(int i=1; i<n; i++){
            s+='0';
        }
        cout << s << endl;
    }
}