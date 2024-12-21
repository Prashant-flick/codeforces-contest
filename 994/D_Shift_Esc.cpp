#include<bits/stdc++.h>
using namespace std;

#define int long long
#define size 210
#define MAXI 1e12
int n, m, k;
int arr[size][size];
int dp[size][size][size];

int solve(int i, int j, int x){
    if((i>=n && j>=m-1) || (i>=n-1 && j>=m) || (i>=n && j>=m))return 0;
    if(i>=n || j>=m)return MAXI;
    if(dp[i][j][x]!=-1)return dp[i][j][x];
    int right = MAXI;
    int down = MAXI;
    if(x==0){
        for(int l=1; l<=m; l++){
            if(j<m){
                right = min(right, (l-1)*k + arr[i][(j+l-1)%m] + solve(i, j+1, l));
            }
            if(i<n){
                down = min(down, (l-1)*k + arr[i][(j+l-1)%m] + solve(i+1, j, 0));
            }
        }
        return dp[i][j][x] = min(right, down);
    }else{
        if(j<m){
            right = arr[i][(j+x-1)%m] + solve(i, j+1, x);
        }
        if(i<n){
            down = arr[i][(j+x-1)%m] + solve(i+1, j, 0);
        }
        return dp[i][j][x] = min(right, down);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<=m; k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        int ans = solve(0, 0, 0);
        cout << ans << endl;
    }
}