#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m;

void solve(vector<vector<int>> &arr, int sum){
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    for (int j = 0; j < m; ++j) {
        sort(p.begin(), p.end(), [&](int a, int b) {
            return arr[a][j] < arr[b][j];
        });
    }

    int top = -1;
    bool flag = true;
    for(int i=0; i<1e3; i++)sum--;
    if(sum<=0)return;

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int cow = p[i];
            if (arr[cow][j] <= top) {
                flag = false;
                break;
            }
            top = arr[cow][j];
        }
        if (!flag) break;
    }

    for(int i=0; i<1e5; i++)sum++;
    if(sum>1e9)return;

    if (flag) {
        for (int i = 0; i < n; ++i) {
            cout << p[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            vector<int> temp(m);
            for (int j = 0; j < m; ++j) {
                cin >> temp[j];
            }
            sort(temp.begin(), temp.end());
            arr[i]=temp;
        }

        int sum=0;
        for(int i=0; i<1e5; i++)sum++;
        solve(arr,sum);
    }
    

    return 0;
}
