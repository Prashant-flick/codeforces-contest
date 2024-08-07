#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,q;

int solve(string &s1, string &s2){
    int dp1[n+1][26]={0};
    int dp2[n+1][26]={0};

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            dp1[i][j] = dp1[i - 1][j];
        }
        for(int j=0; j<26; j++){
            dp2[i][j] = dp2[i - 1][j];
        }
        dp1[i][s1[i-1]-'a']++;
        dp2[i][s2[i - 1] - 'a']++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt1 = 0;
        for (int j = 0; j < 26; ++j) {
            int f = dp1[r][j] - dp1[l - 1][j]; 
            int g = dp2[r][j] - dp2[l - 1][j]; 
            int store = f-g;
            store = abs(store);
            cnt1 = cnt1+store;
        }
        int ans = cnt1/2;
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        cin >> n >> q;
        string s1, s2;
        cin >> s1 >> s2;
        int res = solve(s1, s2);
    }
    return 0;
}