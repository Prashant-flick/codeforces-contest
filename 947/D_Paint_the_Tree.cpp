#include <bits/stdc++.h>
using namespace std;
#define int long long

int size;
int midnode;
int maxi=0;
bool flag=true;
int cnt2=0;

void dfs1(int node, unordered_map<int,vector<int>>& adj, int vis[], int cnt){
    vis[node]=1;
    cnt2++;
    if(adj[node].size()==1 && vis[adj[node][0]]){
        maxi=max(maxi,cnt);
    }
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs1(it,adj,vis,cnt+1);
            cnt2++;
        }
    }
    return;
}

void dfs(int node, unordered_map<int,vector<int>>& adj, int vis[], vector<int>& ls, int node2){
    if(!flag)return;
    vis[node]=1;
    ls.push_back(node);
    if(node==node2){
        size = ls.size();
        midnode = ls[size/2-(size%2==0?1:0)];
        flag=false;
        return;
    }
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls,node2);
            ls.pop_back();
        }
    }
    return;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        maxi=0;
        size=0;
        midnode=0;
        flag=true;
        cnt2=0;
        int n;
        cin >> n;
        int a,b;
        cin >> a >> b;
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n-1; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int vis[n+1]={0};
        vector<int> ls;
        dfs(a, adj, vis, ls, b);

        for(int i=0; i<=n; i++){
            vis[i]=0;
        }
        
        size/=2;
        dfs1(midnode, adj, vis, 0);
        cout << size+cnt2-(maxi+1) << endl;
    }
    return 0;
}
