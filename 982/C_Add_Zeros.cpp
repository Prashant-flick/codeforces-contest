#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 3e5+10;
int arr[N], dp[N];
int maxi,n;

int solve(unordered_map<int,vector<int>> &adj, int i){
    int res=0;
    for(int &v: adj[i]){
        if(dp[v]==-1){
            dp[v] = (v-1)+solve(adj, (i+(v-1)));
        }
        res = max(dp[v], res);
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        cin >> n;
        unordered_map<int,vector<int>> adj;
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            if(i==1)continue;
            adj[arr[i]-((n+1)-i)].push_back(i);
        }

        // for(auto it: adj){
        //     cout << it.first << "--> ";
        //     for(int &v: it.second){
        //         cout << v << " ";
        //     }
        //     cout << endl;
        // }

        maxi=0;
        memset(dp, -1, sizeof dp);
        int res = solve(adj, 0);
        cout << (n+res) << endl;
    }
}