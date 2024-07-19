#include <bits/stdc++.h>
using namespace std;
#define int long long

// unordered_map<int, vector<int>> mp;
const int N = 3e5+10, LS = 19, inf=3e18+20;
int arr[N];
int dp[LS][N];
vector<int> mp[N];

void dfs(int u, int par=-1){
    for(int i=0; i<LS; i++){
        dp[i][u] = (i+1)*arr[u];
    }

    for(int &v: mp[u]){
        if(v==par)continue;

        dfs(v, u);

        int min1=inf, min2=inf;
        for(int i=0; i<LS; i++){
            min2 = min(min2, dp[i][v]);
            if(min1>min2) swap(min1, min2);
        }

        for(int i=0; i<LS; i++){
            int val = min1;
            if(dp[i][v]==val)val=min2;
            dp[i][u]+=val;
        }
    }
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for(int i=0,u,v; i<n-1; i++){
            cin >> u >> v;
            u--;
            v--;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        dfs(0);
        
        int ans=inf;
        for(int i=0; i<LS; i++){
            ans = min(ans, dp[i][0]);
        }

        cout << ans << endl;
        for(int i=0; i<n; i++){
            mp[i].clear();
        }
    }
    return 0;
}