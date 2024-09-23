#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> p;
typedef pair<int,pair<int,pair<int,int>>> p1;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n,m,h;
        cin >> n >> m >> h;
        int horse[n+1]={0};
        for(int i=0; i<h; i++){
			int temp;
			cin >> temp;
			horse[temp]=1;
		}

		unordered_map<int,vector<p>> adj;
		while(m--){
			int u,v,w;
			cin >> u >> v >> w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}

		int vis[n+1][2][2]={0};
		priority_queue<p1, vector<p1>, greater<p1>> pq;
		pq.push({0,{0,{horse[1],1}}});
		pq.push({0,{1,{horse[n],n}}});

		bool flag=false;
		while(!pq.empty()){
			auto it = pq.top();pq.pop();
			int a = it.first;
			int b = it.second.first;
			int h = it.second.second.first;
			int d = it.second.second.second;

			if(vis[d][b][h])continue;
			vis[d][b][h]=1;
			if(vis[d][!b][h] || vis[d][!b][!h]){
				cout << a << endl;
				flag=true;
				break;
			}


			for(pair<int,int> &p2: adj[d]){
				int dis = (h?a+(p2.second)/2 : a+p2.second);
				pq.push({dis,{b,{max(h,horse[p2.first]),p2.first}}});
			}
		}

		if(!flag){
			cout << -1 << endl;
		}
    }
}