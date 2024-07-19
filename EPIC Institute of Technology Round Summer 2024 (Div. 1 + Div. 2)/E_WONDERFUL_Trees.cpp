#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[5005];
int a[5005];
int cnt[5005][5005];
int ans;
void dfs(int x, int h) {
	for(auto i: adj[x]) {
		dfs(i,h+1);
		for(int j=0;j<5005;j++) cnt[x][j]+=cnt[i][j];
	}
	if(a[x]<0) {cnt[x][h]-=a[x]; return;}
	for(int j=0;j<5005;j++) {
		int rem = min(a[x],cnt[x][j]);
		a[x] -= rem;
		cnt[x][j] -= rem;
		ans += rem * (j - h);
	}
}
main() {
	int t; cin >> t; while(t--) {
		int n; cin >> n; ans = 0;
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=1;i<=n;i++) for(int j=0;j<5005;j++) cnt[i][j]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2,p;i<=n;i++) {
			cin >> p;
			a[p]-=a[i];
			adj[p].push_back(i);
		}
		for(int i=1;i<=n;i++) if(!adj[i].size()) a[i]=-6e12;
		dfs(1,0);
		cout << ans << "\n";
	}
}
