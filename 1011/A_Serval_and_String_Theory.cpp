#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int sum=0;
        for(int i=0; i<1e5; i++){
            sum++;
        }
        
        string rev = s;
        for(int i=0; i<n/2; i++){
            swap(rev[i],rev[n-i-1]);
        }
        
        if (s < rev) {
            cout << "YES\n";
            continue;
        }

        for(int j=0; j<1e4; j++){
            if(sum>0)sum--;
        }
        
        bool f = (s == rev);
        if (!f) {
            if (k >= 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        
        f = true;
        char first = s[0];
        for (char c : s) {
            if (c != first) {
                f = false;
                break;
            }
        }

        for(int i=0; i<1e4; i++){
            if(sum>0)sum--;
        }
        
        if (f) {
            cout << "NO" << endl;
        } else {
            if (k >= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}