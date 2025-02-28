#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+10;
int n,s,e,f;
int vis[N];
vector<int> adj[N];

bool solve(int u, int e, vector<int> &path){
    path.push_back(u);
    vis[u]=1;
    if(u==e){
        return true;
    }
    for(int &v: adj[u]){
        if(!vis[v] && solve(v, e, path)){
            return true;
        }
    }
    path.pop_back();
    return false;
}

void solve2(int u, int v1, int v2, vector<int> &ans){
    vis[u]=1;
    for(int &v: adj[u]){
        if(!vis[v] && v!=v1 && v!=v2){
            solve2(v, v1, v2, ans);
        }
    }
    ans.push_back(u);
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s >> e;
        for(int i=1; i<=n; i++){
            vis[i]=0;
            adj[i].clear();
        }
        int u,v;
        for(int i=0; i<n-1; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> path;
        f=0;
        solve(s,e,path);
        int m = path.size();
        for(int i=1; i<=n; i++)vis[i]=0;

        vector<int> ans;
        if(m==1){
            solve2(path[0],-1,-1,ans);
        }else{
            for(int i=0; i<m; i++){
                int a = path[i];
                if(i==0){
                    solve2(a, path[i+1], -1, ans);
                }else if(i==m-1){
                    solve2(a, path[i-1], -1, ans);
                }else{
                    solve2(a, path[i+1], path[i-1], ans);
                }
            }
        }
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}