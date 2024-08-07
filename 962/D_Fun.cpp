#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        long long count = 0;
        for (int a = 1; a <= min(x, n); ++a) {
            int b_max = min(x - a, n / a);
            for (int b = a; b <= b_max; ++b) {
                int c_max = max(0LL, min(x - a - b, (n-a*b)/(a+b)));
                count += c_max;
            }
        }
        cout << count << endl;
    }
    return 0;
}