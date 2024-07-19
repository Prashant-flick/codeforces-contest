#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int A[200004], B[200004];
map<int, int> D;
signed main(){
	int t, n, m, x, ans;
	cin >> t;
	while(t--){
		D.clear(), ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> A[i];
		for(int i = 0; i < n; i++) cin >> B[i];
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> x;
			D[x]++;
		}
		for(int i = 0; i < n; i++) ans |= (B[i] == x);
        // if(!ans){
        //     cout << "NO" << endl;
        //     continue;
        // }
		for(int i = 0; i < n; i++){
			if(A[i] != B[i]){
				if(D[B[i]]) D[B[i]]--;
				else ans = 0;
			}
		}
		cout << (ans? "YES\n" : "NO\n");
	}
	return 0;
}
