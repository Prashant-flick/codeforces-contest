#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n, m;
string s1 = "narek";
int dp[1001][1001][5];

int solve(vector<string> &s, int i, int j, int c){
    if(i>=n){
        return -c;
    }

    if(dp[i][j][c]!=-1e9){
        return dp[i][j][c];
    }    

    int take = ((s[i][j]!=s1[c] && (s[i][j]==s1[0] || s[i][j]==s1[1] || s[i][j]==s1[2] || s[i][j]==s1[3] || s[i][j]==s1[4]))?-1:0) + (((c==4)&&(s[i][j]==s1[c]))?5:0) + solve(s, (j+1==m?i+1:i), (j+1==m?0:j+1), ((s[i][j]==s1[c])?(c+1)%5:c));
    int nottake = -1e9;
    if(j==0){
        nottake = solve(s, i+1, 0, c);
    }

    return dp[i][j][c]=max(take, nottake);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        vector<string> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < 5; ++k){
                    dp[i][j][k] = -1e9;
                }
            }
        }
        cout << solve(s, 0, 0, 0) << endl;
    }
    
}