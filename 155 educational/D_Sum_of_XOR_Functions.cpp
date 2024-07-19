#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
#define int long long
 
int32_t main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int bt = 0; bt < 30; bt++) {
        int cb = 1 << bt;
        vector <int> cnt(2), sm(2);
        cnt[0] = 1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & cb) {
                cur ^= 1;
            }
            cnt[cur]++;
            sm[cur] += i + 1;
            int cv = cnt[cur ^ 1] * (i + 1) - sm[cur ^ 1];
            cv %= MOD;
            ans += cb * cv;
            ans %= MOD;
        }
        cnt.clear();
        sm.clear();
    }
    cout << ans << endl;
    return 0;
}
