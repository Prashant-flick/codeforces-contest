#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
		int arr[n+1];
		int inv[n+1];
		for(int i=1; i<=n; i++){
			cin >> arr[i];
			inv[arr[i]]=i;
		}

		int dp[n+1]={0};
		set<int> st;
		st.insert(0);
		st.insert(n+1);
		for(int i=1; i<=n; i++){
			int p = inv[i];
			int l = *prev(st.lower_bound(p));
			int r = *(st.lower_bound(p));
			int a = p-l;
			int b = r-p;

			if(l!=0){
				int ll = *prev(st.find(l));
				dp[l] += i*(p-ll-1)*b;
				dp[l+1] -= i*(p-ll-1)*b;
				dp[1] += i*a*b;
				dp[l] -= i*a*b;
			}
			dp[l+1] += i*(a-1)*(b);
			dp[p] -= i*(a-1)*(b);
			dp[p+1] += i*(a)*(b-1);
			dp[r] -= i*(a)*(b-1); 
			if(r!=n+1){
				int rr = *next(st.find(r));
				dp[r] += i*(a)*(rr-p-1);
				dp[r+1] -= i*(a)*(rr-p-1);
				dp[r+1] += i*a*b;
				dp[n+1] -= i*a*b;
			}

			st.insert(p);
		}

		cout << dp[1] << " ";
		for(int i=2; i<=n; i++){
			dp[i]+=dp[i-1];
			cout << dp[i] << " ";
		}
		cout << endl;
	
    }
    return 0;
}