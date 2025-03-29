#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        string s;
        cin >> s;
        int n = s.size();
        int l = count(s.begin(), s.end(), 'L');
        int i = count(s.begin(), s.end(), 'I');
        int t = count(s.begin(), s.end(), 'T');
        
        int max_count = max({l, i, t});
        int m_min = max(max_count, (n + 2) / 3);
        int k = 3 * m_min - n;
    
        if (k < 0) {
            cout << -1 << endl;
            continue;
        }
    
        int required_L = m_min - l;
        int required_I = m_min - i;
        int required_T = m_min - t;
    
        if (required_L < 0 || required_I < 0 || required_T < 0 || required_L + required_I + required_T != k) {
            cout << -1 << endl;
            continue;
        }
    
        bool has_diff_pair = false;
        for (int j = 0; j + 1 < s.size(); ++j) {
            if (s[j] != s[j+1]) {
                has_diff_pair = true;
                break;
            }
        }
    
        if (!has_diff_pair) {
            if (l == i && i == t) {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
    
        vector<char> chars(s.begin(), s.end());
        vector<pair<int, char>> ops;
    
        int last_pos = 0;
        while (required_L > 0 || required_I > 0 || required_T > 0) {
            bool inserted = false;
            vector<pair<int, char>> options;
            if (required_T > 0) options.emplace_back(required_T, 'T');
            if (required_I > 0) options.emplace_back(required_I, 'I');
            if (required_L > 0) options.emplace_back(required_L, 'L');
            sort(options.begin(), options.end(), greater<pair<int, char>>());
    
            for (auto &opt : options) {
                char c = opt.second;
                int start = last_pos;
                for (int step = 0; step < chars.size() - 1; ++step) {
                    int j = (start + step) % (chars.size() - 1);
                    char a = chars[j], b = chars[j+1];
                    if (a != b && a != c && b != c) {
                        chars.insert(chars.begin() + j + 1, c);
                        ops.push_back({j + 1, c});
                        if (c == 'T') required_T--;
                        else if (c == 'I') required_I--;
                        else required_L--;
                        inserted = true;
                        last_pos = (j + 1) % (chars.size() - 1);
                        break;
                    }
                }
                if (inserted) break;
            }
    
            if (!inserted) {
                cout << -1 << endl;
                continue;
            }
        }
    
        cout << ops.size() << endl;
        for (auto& p : ops) {
            cout << p.first << endl;
        }
    
    }
    
   
    return 0;
}