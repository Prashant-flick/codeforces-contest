#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n,s1,s2,u,v;
        cin >> n >> s1 >> s2;
        int w1;
        cin >> w1;
        vector<int> arr[n+1];
        vector<int> brr[n+1];
        while (w1--)
        {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        cin >> w1;
        while (w1--)
        {
            cin >> u >> v;
            brr[u].push_back(v);
            brr[v].push_back(u);
        }

        int vis[n+1]={0};
        for(int i=1; i<=n; i++){
            set<int> st(arr[i].begin(), arr[i].end());
            for(int &v: brr[i]){
                if(st.count(v)){
                    vis[i]=1;
                    break;
                }
            }
        }
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0,s1,s2});
        int d[n+1][n+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                d[i][j]=1e9;
            }
        }
        d[s1][s2]=0;
        int ans=-1;
        while(!pq.empty()){
            auto [a,b,c] = pq.top();
            pq.pop();
            if(b==c && vis[b]){
                ans=a;
                break;
            }
            
            for(int &u: arr[b]){
                for(int &v: brr[c]){
                    int newd = a + abs(v-u);
                    if(newd<d[u][v]){
                        d[u][v]=newd;
                        pq.push({newd,u,v});
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
}