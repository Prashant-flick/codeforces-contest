#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> ps(100001), ts(100001);
int total;
int n;
int m;
int sp,st;
int th,ph;

void function1(vector<int>& ap, vector<int>& at){
    sp = 0, st = 0;
    ph = 0, th = 0;

    for (int i = 0; i < total; ++i) {
        if (ps[i] > ts[i] && ph <= n) {
            sp += ps[i];
            ph += 1;
            ap[i] = 1;
        } else if (ps[i] < ts[i] && th < m) {
            sp += ts[i];
            th += 1;
            ap[i] = 0;
        } else if (ph <= n) {
            sp += ps[i];
            ph += 1;
            ap[i] = 1;
        } else {
            sp += ts[i];
            th += 1;
            ap[i] = 0;
        }
    }

    th = 0;ph = 0;
    for (int i = 0; i < total; ++i) {
        if (ps[i] < ts[i] && th <= m) {
            st += ts[i];
            th += 1;
            at[i] = 0;
        } else if (ps[i] > ts[i] && ph < n) {
            st += ps[i];
            ph += 1;
            at[i] = 1;
        } else if (th <= m) {
            st += ts[i];
            th += 1;
            at[i] = 0;
        } else {
            st += ps[i];
            ph += 1;
            at[i] = 1;
        }
    }

    return;
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        total = n + m + 1;
        
        for (int i = 0; i < total; ++i) cin >> ps[i];
        for (int i = 0; i < total; ++i) cin >> ts[i];
        
        vector<int> ap(total), at(total);
        function1(ap, at);

        for (int i = 0; i < total; ++i) {
            int teamSkill = 0;
            if (ap[i] == 1) {
                teamSkill = sp - ps[i];
            } else if (at[i] == 0) {
                teamSkill = st - ts[i];
            }
            cout << teamSkill << " ";
        }
        cout << endl;
    }
    return 0;
}