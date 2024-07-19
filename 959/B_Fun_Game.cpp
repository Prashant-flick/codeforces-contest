#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        if(s==t){
            cout << "YES" << endl;
            continue;
        }
        int index=-1;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                index=i;
                break;
            }
        }
        if(index==-1){
            cout << "NO" << endl;
            continue;
        }
        
        bool flag=true;
        for(int i=n-1; i>=0; i--){
            if(s[i]!=t[i]){
                if(i<index){
                    flag=false;
                    break;
                }
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}