#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        vector<int> pre(m);
        pre[0] = arr[0];
        for (int i = 1; i < m; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }

        int ans = 0;
        for (int i = 0; i < m - 1; i++) {
            int a = n-arr[i], b = n;
            int idx1 = lower_bound(arr.begin() + i + 1, arr.end(), a) - arr.begin();
            int idx2 = lower_bound(arr.begin()+i+1, arr.end(), b) - arr.begin();
            if (idx1 == m) continue;
            if(idx1==idx2){
                int size = m-idx2;
                ans+=min(n-1, arr[i])*size;
            }else{
                int sum = pre[idx2-1]-(idx1==0?0:pre[idx1-1]);
                int size = idx2-idx1;
                int totsum = sum+(size*arr[i]);
                int rem = totsum - (n*size);
                ans+=rem+size;

                size = m-idx2;
                ans+=min(n-1, arr[i])*size;
            }
        }
        ans *= 2LL;
        cout << ans << endl;
    }
}
