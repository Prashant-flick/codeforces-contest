#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,u,v;
    cin >> n;
    unordered_map<int,set<int>> adj;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int dist[n+1];
    vector<pair<int,int>> cnt;
    for(auto &it: adj){
        dist[it.first]=it.second.size();
        cnt.push_back({it.second.size(),it.first});
    }

    sort(cnt.rbegin(), cnt.rend());
    if(cnt[0].first==cnt[1].first){
        int a = cnt[0].first;
        int i=1;
        bool flag=false;
        int cnt2=0;
        for(;i<cnt.size() && cnt[i].first==a;i++){
            if(adj[cnt[0].second].find(cnt[i].second)==adj[cnt[0].second].end()){
                flag=true;
                break;
            }
            cnt2++;
            if(cnt2==2)break;
        }
        if(cnt2==2)flag=true;
        cout << (2*a)-(flag?1:2) << endl;
        return;
    }
    int a = cnt[0].first;
    int b = cnt[1].first;
    int i=1;
    bool flag=false;
    for(;i<cnt.size() && cnt[i].first==b;i++){
        if(adj[cnt[0].second].find(cnt[i].second)==adj[cnt[0].second].end()){
            flag=true;
            break;
        }
    }
    cout << (a+b)-(flag?1:2) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}