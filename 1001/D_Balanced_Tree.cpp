#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n;
        vector<pair<int,int>> vec(n+1);
        for(int i=1; i<=n; i++){
            cin >> l >> r;
            vec[i] = {l,r};
        }
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n-1; i++){
            cin >> l >> r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }

        
    }
}