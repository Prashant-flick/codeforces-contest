#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5+10;
int a[N],A[N],Size[N],pre[N],opre[N],Map[N];
int t,n,u,v,ans,cnt;
vector<int> adj[N];

void dfs(int u, int par){
    Size[u]=1,Map[u]=++cnt,A[cnt]=a[u];
    for(int &v: adj[u]){
        if(par!=v){
            dfs(v,u);
            Size[u]+=Size[v];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            adj[i].clear();
        }
        for(int i=1; i<n; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans=pre[0]=opre[n+1]=cnt=a[0]=0;
        dfs(1,0);
        for(int i=1; i<=n; i++){
            pre[i]=max(pre[i-1],A[i]);
        }
        for(int i=n; i>0; i--){
            opre[i]=max(opre[i+1],A[i]);
        }
        for(int i=1; i<=n; i++){
            if((max(pre[Map[i]-1], opre[Map[i]+Size[i]])>a[i]&&a[i]>a[ans]))ans=i;
        }
        if(ans){
            
            continue;
        }
        cout << ans << endl;
    }
}