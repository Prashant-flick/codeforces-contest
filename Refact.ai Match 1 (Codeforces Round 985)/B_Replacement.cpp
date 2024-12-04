#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, r;
        cin >> s >> r;
        
        stack<char> temp;
        int j = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                temp.push(s[i]);
            } else {
                temp.push(s[i]);
                char prev = s[i + 1];
                
                while (j < n - 1 && !temp.empty() && prev != temp.top()) {
                    temp.pop();
                    prev = r[j];
                    j++;
                }
                
                s[i + 1] = prev;
            }
        }

        if (temp.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
