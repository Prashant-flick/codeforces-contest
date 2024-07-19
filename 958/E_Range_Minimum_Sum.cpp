#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n), inv(n+1);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			inv[a[i]] = i;
		}

		vector<long long int> dAns(n+1);

		set<long long int> s;
		s.insert(-1), s.insert(n);
		for(int i = 1; i <= n; i++) {
			// set<long long int> s;
			// s.insert(-1), s.insert(n);
			// int k = inv[i];
			// for(int j=0; j<n; j++){
			// 	if(i==j)continue;
			// 	long long int p = inv[j]; 
			// 	long long int l = *prev(s.lower_bound(p));
			// 	long long int r = *(s.lower_bound(p));
			// 	// cout << p << " " << l << " " << r << endl;
			// 	if(k<r && k>p){
			// 		dAns[i]+=(j+1)*((p-l)*(r-p-1));
			// 	}else if(k<p && k>l){
			// 		dAns[i]+=(j+1)*((p-l-1)*(r-p));
			// 	}else{
			// 		dAns[i]+=(j+1)*((p-l)*(r-p));
			// 	}
			// 	s.insert(p);
			// }
			long long int p = inv[i];
			long long int l = *prev(s.lower_bound(p));
			long long int r = *(s.lower_bound(p));
			if(l != -1) {
				long long int ll = *prev(s.find(l));
				dAns[0] += i*(p-l)*(r-p);
				dAns[l] -= i*(p-l)*(r-p);
				dAns[l] += i*(p-ll-1)*(r-p);
				dAns[l+1] -= i*(p-ll-1)*(r-p);
			}
			dAns[l+1] += i*(p-l-1)*(r-p);
			dAns[p] -= i*(p-l-1)*(r-p);
			dAns[p+1] += i*(p-l)*(r-p-1);
			dAns[r] -= i*(p-l)*(r-p-1);
			if(r != n) {
				long long int rr = *next(s.find(r));
				dAns[r] += i*(p-l)*(rr-p-1);
				dAns[r+1] -= i*(p-l)*(rr-p-1);
				dAns[r+1] += i*(p-l)*(r-p);
				dAns[n] -= i*(p-l)*(r-p);
			}
			s.insert(p);
		}

		// for(int i=0; i<n; i++){
		// 	cout << dAns[a[i]] << " ";
		// }
		// cout << endl;
		cout << dAns[0] << " ";
		for(int i = 1; i < n; i++) {
			dAns[i] += dAns[i-1];
			cout << dAns[i] << " ";
		}
		cout << endl;
	}
	return 0;
}