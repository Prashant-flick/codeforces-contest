#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = (int)1e6+5;
const int N = (int)1e6;

int n, q; ll ans;
int mc[MAXN], dp[MAXN]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	int a[n];
	int b[n];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	memset(mc, 60, sizeof mc);
	for (int i = 1; i <= n; i++) {
		mc[a[i]] = min(mc[a[i]], a[i]-b[i]);
	} 
	for (int i = 1; i <= N; i++) {
		mc[i] = min(mc[i], mc[i-1]);
		if (i < mc[i]) continue;
		dp[i] = dp[i-mc[i]] + 2;
	}
	
	int x;
	while (q--) {
		cin >> x;
		if (x > N) {
			int tms = (x - N + (mc[N]-1)) / mc[N];
			ans += tms * 2;	
			x -= tms * mc[N];
		} 
		ans += dp[x];
	}
	
	cout << ans;
	return 0;
}