#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0]=='1' || s[n-1]=='1'){
            cout << "YES" << endl;
            continue;
        }
        bool flag=false;
        for(int i=0; i<n-1; i++){
            if(s[i]=='1' && s[i+1]=='1'){
                flag=true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}