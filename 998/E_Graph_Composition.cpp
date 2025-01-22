#include<bits/stdc++.h>
using namespace std;

int solve2(vector<unordered_map<int,int>> &adj, vector<set<int>> &vec, unordered_map<int,int> &store, int *vis, int u, int flag1, int flag2){
    vis[u]=1;
    int res=0;

    for (auto &it: adj[u]) {
        if (it.second==1 && !vis[it.first]) {
            if (vec[store[u]].find(it.first) != vec[store[u]].end()) {
                adj[u][it.first]=-1;
                adj[it.first][u]=-1;
                res += solve2(adj, vec, store, vis, it.first, 0, 1);
            } else {
                adj[u][it.first]=0;
                adj[it.first][u]=0;
                res += 1+solve2(adj, vec, store, vis, it.first, 1, 0);
            }
        } else if (it.second==1) {
            if(vec[store[u]].find(it.first) != vec[store[u]].end()) {
                adj[u][it.first]=-1;
                adj[it.first][u]=-1;
            }else{
                adj[u][it.first]=0;
                adj[it.first][u]=0;
                res++;
            }
        }
    }

    return res;
}

void solve(vector<vector<int>> &adj, set<int> &st, int *vis, int u){
    st.insert(u);
    vis[u]=1;
    for(int &v: adj[u]){
        if(!vis[v]){
            solve(adj, st, vis, v);
        }
    }
}

void solve3(vector<unordered_map<int,int>> &adj, int *vis, int u){
    vis[u]=1;
    for(auto &v: adj[u]){
        if(!vis[v.first] && (v.second==-1 || v.second==1)){
            solve3(adj, vis, v.first);
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
        vector<unordered_map<int,int>> edges1(n+1);
        vector<vector<int>> edges2(n+1);
        int cnt=0;
        for(int i=0; i<m1; i++){
            cin >> u >> v;
            edges1[u][v]=1;
            edges1[v][u]=1;
        }

        for(int i=0; i<m2; i++){
            cin >> u >> v;
            edges2[u].push_back(v);
            edges2[v].push_back(u);
        }

        vector<set<int>> vec;
        unordered_map<int,int> store;
        int vis[n+1]={0};
        int j=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                set<int> st;
                solve(edges2, st, vis, i);
                vec.push_back(st);
                for(auto &it: st){
                    store[it]=j;
                }
                j++;
            }
        }

        int ans=0;
        fill(vis, vis+(n+1), 0);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                ans+=solve2(edges1, vec, store, vis, i, 1, 0);
            }
        }

        fill(vis, vis+(n+1), 0);
        for(set<int> &st: vec){
            int cnt=0;
            for(const int &it: st){
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