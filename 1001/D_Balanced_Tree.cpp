#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+10;
int l[N],r[N],a[N];
int ans,u,v,n,t;
vector<int> adj[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> l[i] >> r[i];
            adj[i].clear();
        }
        for(int i=1; i<n; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans=0;
        auto dfs = [&](auto &&dfs, int x, int par)->void {
            int maxi = l[x];
            for(int &y: adj[x]){
                if(y!=par){
                    dfs(dfs,y,x);
                    maxi=max(maxi,a[y]);
                }
            }
            a[x]=min(r[x],maxi);
            for(int &y: adj[x]){
                if(y!=par)ans+=max(0LL,(a[y]-a[x]));
            }
        };
        dfs(dfs,1,0);
        cout << ans+a[1] << endl;
    }
}