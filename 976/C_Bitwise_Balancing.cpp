#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int b, c, d;
        cin >> b >> c >> d;

        if (b - c > d) {
            cout << -1 << endl;
            continue;
        }

        int cnt[60] = {0}, cnt2[60] = {0};

        for (int i = 0; i < 60; i++) {
            if (c & (1LL << i)) cnt[i] = 1;
            if (b & (1LL << i)) cnt2[i] = 1;
        }

        int c1 = 0;
        int b1 = c1 + d;

        if (b1 >= b) {
            int cnt1 = 0;
            bool flag = true;
            for (int k = 0; k < 60; k++) {
                if (!cnt2[k] && (b1 & (1LL << k)) && cnt[k] && !(c1 & (1LL << k))) {
                    flag = false;
                    break;
                } else if (!cnt2[k] && (b1 & (1LL << k))) {
                    cnt1 += (1LL << k);
                }
            }

            if (flag && ((cnt1 | b) == b1)) {
                cout << cnt1 << endl;
                continue;
            }
        }

        int i = 0;
        int ans = INT64_MAX;

        while (i < 60) {
            while (i < 60 && cnt[i] == 0) {
                i++;
            }
            if (i == 60) break;
            int j = i;
            int c1 = 0;
            while (j < 60) {
                while (j < 60 && cnt[j] == 0) {
                    j++;
                }
                if (j == 60) break;
                c1 += (1LL << j);
                int b1 = c1 + d;
                if (b1 < b) {
                    j++;
                    continue;
                }

                bool flag = true;
                int cnt1 = c1;
                for (int k = 0; k < 60; k++) {
                    if (!cnt2[k] && (b1 & (1LL << k)) && cnt[k] && !(c1 & (1LL << k))) {
                        flag = false;
                        break;
                    } else if (!cnt2[k] && (b1 & (1LL << k))) {
                        cnt1 += (1LL << k);
                    }
                }

                if (flag && ((cnt1 | b) == b1)) {
					ans = min(ans, cnt1);
                }
                j++;
            }
            i++;
        }

        if(ans==INT64_MAX){
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
}
