#include <bits/stdc++.h>
using namespace std;
#define int long long

// int dp[100001];

int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt1=0;
        int cnt2=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                while(s[i]=='0'){
                    i++;
                }
                cnt1++;
            }else{
                cnt2++;
                i++;
            }
        }
        if(cnt2>cnt1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}