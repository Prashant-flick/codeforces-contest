#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 3e5+10;
int n,m;
int arr[N],brr[N];

int solve(int i, int j, vector<vector<int>> &dp, vector<int> &pre){
    if(i>=m){
        return 1e12;
    }
    if(j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int idx = upper_bound(pre.begin(), pre.end(), (j!=0?pre[j-1]:0)+brr[i]) - pre.begin();
    idx--;
    int take = 1e12;
    int not_take = 1e12;
    if(idx>=j){
        take = (m-(i+1)) + solve(i, idx+1, dp, pre);
        not_take = solve(i+1, j, dp, pre);
    }

    return dp[i][j]=min(take, not_take);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int maxi=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi=max(maxi,arr[i]);
        }
        for(int i=0; i<m; i++)cin >> brr[i];
        if(brr[0]<maxi){
            cout << -1 << endl;
            continue;
        }

        vector<int> pre(n);
        for(int i=0; i<n; i++){
            pre[i]=i!=0?pre[i-1]+arr[i]:arr[i];
        }

        vector<vector<int>> dp(m, vector<int> (n,-1));
        int res = solve(0, 0, dp, pre);
        cout << res << endl;
    }
}