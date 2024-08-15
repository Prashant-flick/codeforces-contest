#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
const int N = 3e5 + 10;
int a[N], n, k, b[N];

vector<int> v, v2;

int get(int K, int bb = 0){
	int l = 1, r = 2e9;

	while (l + 1 < r){
		int mid = (l + r) / 2;
		int kk = k;
		int cnt = 0;
		for (int i=v.size()-1;i>=0;i--){
			if (v[i] >= mid){
				cnt++;
				continue;
			}
			if (kk < mid - v[i])
				break;
			int kkk = mid - v[i];
			kk -= kkk;
			cnt++;
		}

		int u = upper_bound(begin(v2), end(v2), mid - 1) - begin(v2);
		u = v2.size() - u;
		u = max(0LL, u - bb);
		if (cnt + u >= K)
			l = mid;
		else
			r = mid;
	}
	return l;
}

void solve(){
	v.clear();
	v2.clear();
	cin>>n>>k;

	for (int i=1;i<=n;i++)
		cin>>a[i];
	
	vector<pair<int,int>> vec = {{0,0}};

	for (int i=1;i<=n;i++){
		cin>>b[i];
		if (b[i] == 1)
			v.push_back(a[i]);
		else
			v2.push_back(a[i]);
		vec.push_back({a[i], b[i]});
	}
	sort(begin(v2), end(v2));
	sort(begin(v), end(v));


	// cout<<get(2, 1)<<'\n';
	// return ;


	int m1 = n - n / 2;

	int l1 = get(m1);
	int l2 = get(m1, 1);
	// cout<<l1<<" "<<l2<<'\n';

	sort(begin(vec), end(vec));
	int ans = 0;

	for (int i=1;i<=n;i++){
		if (vec[i].second == 1){
			int md = n / 2;
			if (i <= md)
				md++;
			ans = max(ans, vec[i].first + vec[md].first + k);
		}
		else if (vec[i].first < l1)
			ans = max(ans, vec[i].first + l1);
		else
			ans = max(ans, vec[i].first + l2);
	}

	cout<<ans<<'\n';

}

signed main(){
	int t;
	cin>>t;
	while (t--)
		solve();
}
