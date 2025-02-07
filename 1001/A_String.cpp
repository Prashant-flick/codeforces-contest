#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n=s.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}