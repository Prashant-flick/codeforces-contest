#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 200000
int i, j, k, n, m, t, a[N+50], b[N+50], pa[N+50], pb[N+50];
ll w1, w2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (i = n, pa[n+1] = pb[n+1] = 0; i >= 0; i--) {
            pa[i] = __gcd(pa[i+1], a[i]);
            pb[i] = __gcd(pb[i+1], b[i]);
        }
        w1 = w2 = 0;
        map<pair<int, int>, ll> f[2], g[2]; 
        f[0][{0, 0}] = 1;
        
        for (i = 1; i <= n+1; i++) {
            for (j = 0; j <= 1; j++) {
                for (auto it = f[j].begin(); it != f[j].end(); ++it) {
                    auto p = it->first;
                    auto w = it->second;
                    int x = p.first;
                    int y = p.second;
                    
                    int xa = __gcd(x, a[i]);
                    int xb = __gcd(x, b[i]);
                    int ya = __gcd(y, a[i]);
                    int yb = __gcd(y, b[i]);

                    if (j == 0) {
                        g[0][{xa, yb}] += w;
                        g[1][{xb, ya}] += w;
                    } else if (j == 1) {
                        g[1][{xb, ya}] += w;
                        x = __gcd(x, pa[i]);
                        y = __gcd(y, pb[i]);
                        
                        if (x + y > w1) {
                            w1 = x + y;
                            w2 = w;
                        } else if (x + y == w1) {
                            w2 += w;
                        }
                    }
                }
                f[j] = g[j];
                g[j].clear();
            }
        }
        cout << w1 << ' ' << w2 << '\n';
    }
}
