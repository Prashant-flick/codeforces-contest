#include<bits/stdc++.h>
using namespace std;

int solve2(unordered_map<int,set<int>> &adj, set<int> &st, int *vis, int u, int *vis2, int flag){
    vis[u]=1;
    int cnt=adj[u].size()-flag;
    int res=0;

    vector<int> to_remove;
    for (const int &it : adj[u]) {
        if (!vis[it] && st.find(it) != st.end()) {
            cnt--;
            vis2[it] = 1;
            res += solve2(adj, st, vis, it, vis2, 1);
        } else if (!vis[it]) {
            to_remove.push_back(it);
        }
    }

    for (const int &it : to_remove) {
        adj[u].erase(it);
        adj[it].erase(u);
    }

    return res + cnt;
}

void solve(unordered_map<int,vector<int>> &adj, set<int> &st, int *vis, int u){
    st.insert(u);
    vis[u]=1;
    for(int &v: adj[u]){
        if(!vis[v]){
            solve(adj, st, vis, v);
        }
    }
}

void solve3(unordered_map<int,set<int>> &adj, int *vis, int u){
    vis[u]=1;
    for(const int &v: adj[u]){
        if(!vis[v]){
            solve3(adj, vis, v);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m1,m2,u,v;
        cin >> n >> m1 >> m2;
        unordered_map<int,set<int>> edges1;
        unordered_map<int,vector<int>> edges2;
        for(int i=0; i<m1; i++){
            cin >> u >> v;
            edges1[u].insert(v);
            edges1[v].insert(u);
        }

        for(int i=0; i<m2; i++){
            cin >> u >> v;
            edges2[u].push_back(v);
            edges2[v].push_back(u);
        }

        vector<set<int>> vec;
        int vis[n+1]={0};
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                set<int> st;
                solve(edges2, st, vis, i);
                vec.push_back(st);
            }
        }

        int ans=0;
        int vis2[n+1]={0};
        for(set<int> &st: vec){
            for(auto it: st){
                if(!vis2[it]){
                    vis2[it]=1;
                    memset(vis, 0, sizeof vis);
                    ans+=solve2(edges1, st, vis, it, vis2, 0);
                }
            }
        }

        memset(vis, 0, sizeof vis);
        for(set<int> &st: vec){
            int cnt=0;
            for(auto it: st){
                if(!vis[it]){
                    solve3(edges1, vis, it);
                    cnt++;
                }
            }
            ans+=cnt-1;
        }


        cout << ans << endl;
    }
}