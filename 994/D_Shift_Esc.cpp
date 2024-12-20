// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define size 210
// int n, m, k;
// int arr[size][size];
// int dp[size][size][size][2];

// int solve(int i, int j, int x, int check){
//     if((i>=n && j>=m-1) || (i>=n-1 && j>=m) || (i>=n && j>=m))return 0;
//     if(i>=n || j>=m)return INT_MAX;
//     if(dp[i][j][x][check]!=-1)return dp[i][j][x][check];
//     int right = INT_MAX;
//     int down = INT_MAX;
//     int right1 = INT_MAX;
//     if(check){
//         if(j<m){
//             right = arr[i][(j+x)%m] + solve(i, j+1, x, 1);
//         }
//         if(i<n){
//             down = arr[i][(j+x)%m] + solve(i+1, j, 0, 0);
//         }
//         return dp[i][j][x][check] = min(right, down);
//     }else{
//         if(j<m){
//             right = (x)*k + arr[i][(j+x)%m] + solve(i, j+1, x, 1);
//         }
//         if(x<m){
//             right1 = solve(i, j, x+1, 0);
//         }
//         if(i<n){
//             down = (x)*k + arr[i][(j+x)%m] + solve(i+1, j, 0, 0);
//         }
//         return dp[i][j][x][check] = min(right, min(down,right1));
//     }
// }

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);

//     int t;
//     cin >> t;
//     while(t--){
//         cin >> n >> m >> k;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 cin >> arr[i][j];
//             }
//         }
        
//         memset(dp, -1, sizeof dp);
//         int ans = solve(0, 0, 0, 0);
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 for(int k=0; k<m; k++){
//                     for(int l=0; l<2; l++){
//                         cout << dp[i][j][k][l] << " ";
//                     }
//                     cout << endl;
//                 }
//                 cout << endl;
//             }
//             cout << endl;
//         }
//         cout << ans << endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define size 210
int n, m, k;
int arr[size][size];
int dp[size][size][size];

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
        
        memset(dp, 0x3f, sizeof dp);

        for(int i=n; i>=0; i--){
            for(int j=m; j>=0; j--){
                for(int x=m; x>=0; x--){
                    if((i>=n && j>=m-1) || (i>=n-1 && j>=m) || (i>=n && j>=m)){
                        dp[i][j][x] = 0;
                        continue;
                    }
                    if(i>=n || j>=m){
                        dp[i][j][x] = INT_MAX;
                        continue;
                    }

                    int right = INT_MAX;
                    int down = INT_MAX;
                    int right1 = INT_MAX;

                    if(j < m){
                        right = arr[i][(j+x)%m] + dp[i][j+1][x];
                    }
                    if(i < n){
                        down = arr[i][(j+x)%m] + dp[i+1][j][0];
                    }
                    if(x < m){
                        right1 = dp[i][j][x+1];
                    }
                    dp[i][j][x] = min(right, min(down, right1));
                }
            }
        }

        int ans = dp[0][0][0];
        cout << ans << endl;
    }
}
