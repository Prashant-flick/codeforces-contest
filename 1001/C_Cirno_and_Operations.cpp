#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e12
#define INF2 1e16
int n;
int dp[51][2];

int solve(vector<int> &arr, int i,bool flag){
    if(i>=n-1)return -INF;
    if(dp[i][flag]!=-INF2)return dp[i][flag];
    int rever = -INF;
    int findsum = -INF;
    if(!flag){
        reverse(arr.begin(), arr.end());
        rever = solve(arr, i, true);
        reverse(arr.begin(), arr.end());
    }
    int newsum = 0;
    vector<int> temp;
    for(int j=0; j<arr.size()-1; j++){
        temp.push_back(arr[j+1]-arr[j]);
        newsum+=temp[j];
    }
    findsum = solve(temp, i+1, false);
    return dp[i][flag] = max(rever, max(findsum, newsum));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n);
        int sum=0LL;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum=(sum+arr[i]+0LL);
        }

        for(int i=0; i<n+1; i++){
            for(int j=0; j<2; j++){
                dp[i][j]=-INF2;
            }
        }
        cout << max(sum,solve(arr, 0, false)) << endl;
    }
}