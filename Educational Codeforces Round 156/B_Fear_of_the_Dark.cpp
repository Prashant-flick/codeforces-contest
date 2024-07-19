#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

#define int long double

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int hx, hy, l1x, l1y, l2x, l2y;
        cin >> hx >> hy >> l1x >> l1y >> l2x >> l2y;
        if (hx == 0 && hy == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout.precision(11);
            int l1O = sqrtl((abs(l1x) * abs(l1x)) + (abs(l1y) * abs(l1y)));
            int l2O = sqrtl((abs(l2x) * abs(l2x)) + (abs(l2y) * abs(l2y)));
            int l1h = sqrtl((abs(l1x - hx) * abs(l1x - hx)) + (abs(l1y - hy) * abs(l1y - hy)));
            int l2h = sqrtl(((abs(l2x - hx) * abs(l2x - hx)) + (abs(l2y - hy) * abs(l2y - hy))));
            int l1l2 = sqrtl(((abs(l2x - l1x) * abs(l2x - l1x)) + (abs(l2y - l1y) * abs(l2y - l1y))));
            l1l2 /= 2;
            int min1 = max(l1O, l1h);
            int min2 = max(l2O, l2h);

            int min3 = max({min(l1h, l2h), min(l1O, l2O), l1l2});
            cout << min({min1, min2, min3}) << endl;
        }
    }
    return 0;
}
