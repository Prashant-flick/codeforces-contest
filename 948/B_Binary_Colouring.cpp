#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector<int> vec(32, 0);
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) {
                if (i < 31 && (x & (1 << (i + 1)))) {
                    x += (1 << (i + 1));
                    vec[i] = -1;
                } else {
                    vec[i] = 1;
                }
            }
        }

        vector<int> ans;
        for (int i = 31; i >= 0; i--) {
            if (vec[i] != 0) {
                for (int j = 0; j <= i; j++) {
                    ans.push_back(vec[j]);
                }
                break;
            }
        }

        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
