#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5 + 10;
int n, u, v;
int arr[N], par[N], vis[N], vec[N], store1[N];
vector<int> adj[N];

void dfs(int u, int p) {
    vec[u]=store1[arr[u]];
    par[u] = p;
    if(u!=1){
        store1[arr[u]]++;
    }
    for (int &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    if(u!=1){
        store1[arr[u]]--;
    }
}

int solve(int u, int check, int f, unordered_map<int, int> &mp, unordered_map<int, vector<int>> &store2) {
    vis[u] = 1;
    if (par[u] == u) {
        return 2;
    }
    store2[arr[u]].push_back(u);
    mp[arr[u]]--;
    if (arr[u] == check) {
        return f?1:0;
    }
    if(vis[par[u]]){
        return false;
    }
    return solve(par[u], check, f, mp, store2);
}

bool check(int u, int v) {
    while(u!=par[u]){
        if(vis[par[u]] || par[u]==v)return true;
        u=par[u];
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> st;
        unordered_map<int, vector<int>> store;
        unordered_map<int, vector<int>> store2;
        unordered_map<int,int> mp,mp1;
        
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            store1[arr[i]]=0;
            vec[i]=0;
            adj[i].clear();
            vis[i]=0;
            if(i>1){
                store[arr[i]].push_back(i);
                mp[arr[i]]++;
                mp1[arr[i]]++;
            }
            if(mp1[arr[i]]==1)st.push_back(arr[i]);
        }
        if(mp1[arr[1]]==0)st.push_back(arr[1]);
        
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(1, 1);
        auto it = st.begin();
        int flag = 0;
        vector<int> ans;
        sort(st.rbegin(), st.rend());
        
        for (int j=0; j+1<st.size(); j++) {
            int a = st[j];
            int b = st[j+1];
            if(mp1[b]<=0){
                continue;
            }
            if (arr[1] == a) {
                ans = store[b];
                flag = 1;
                break;
            }
            if(mp[b]<mp1[b]){
                ans = store[b];
                flag=1;
                break;
            }

            int i = 0;
            for (int &u : store[a]) {
                flag = solve(u, b, i, mp, store2);
                if (flag) break;
                i++;
            }
             
            if (flag) {
                if (flag == 2) {
                    ans = store[b];
                    break;
                }
                int c = store2[b][0], d = store2[b][1];
                if(check(c, d)){
                    ans.push_back(c);
                    while(!vis[c]){
                        c = par[c];
                        vis[c]=1;
                        if(arr[c]==b){
                            mp[b]--;
                            ans.push_back(c);
                        }
                    }
                    int cnt = vec[d];
                    if(mp[b] > cnt){
                        ans = store[b];
                    }
                }else{
                    ans.push_back(d);
                    while(!vis[d]){
                        d = par[d];
                        vis[d]=1;
                        if(arr[d]==b){
                            mp[b]--;
                            ans.push_back(d);
                        }
                    }
                    int cnt = vec[c];
                    if(mp[b] > cnt){
                        ans = store[b];
                        for(int &v: store[b]){

                        }
                    }
                }
                break;
            }
            
            int cnt = vec[store2[b][0]];
            
            if (mp[b] > cnt) {
                cout << "here5" << endl;
                flag = true;
                int vis2[n+1]={0};
                int u = store2[b][0];
                vis2[u] = 1;
                int v = u;
                while (par[par[v]] != par[v]) {
                    v = par[v];
                    vis2[v] = 1;
                }
                for (int &u : store[b]) {
                    if (!vis2[u]) {
                        ans.push_back(u);
                        break;
                    }
                }
                break;
            }
        }
        
        if(flag){
            cout << ans.size() << " ";
            for(int i=0; i<ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }else{
            cout << 0 << endl;
        }
    }
}