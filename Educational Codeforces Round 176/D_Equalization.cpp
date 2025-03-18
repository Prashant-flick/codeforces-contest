#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> solve(int a, vector<int> &vis) {
    int target = a;

    vector<int> dp(target + 1, LLONG_MAX);
    vector<int> prev(target + 1, -1);

    dp[0] = 0;

    for (int num = 1; num <= target; num++) {
        if (vis[num]) continue; // Skip if already visited
        for (int sum = target; sum >= num; sum--) {
            if (dp[sum - num] != LLONG_MAX) {
                int newSquareSum = dp[sum - num] + num * num;
                if (newSquareSum < dp[sum]) {
                    dp[sum] = newSquareSum;
                    prev[sum] = num;
                }
            }
        }
    }

    vector<int> result;
    int curr = target;

    while (curr > 0) {
        if (prev[curr] == -1) break;
        result.push_back(prev[curr]);
        vis[prev[curr]] = 1; // Mark as visited after choosing
        curr -= prev[curr];
    }

    return result;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y > x) swap(x, y);

        int arr[65] = {0}, brr[65] = {0};
        for (int i = 0; i < 64; i++) {
            if ((1LL << i) & x) {
                arr[i] = 1;
            }
            if ((1LL << i) & y) {
                brr[i] = 1;
            }
        }

        int i = 63, j = 63;
        while (i >= 0 && arr[i] == 0) {
            i--;
        }
        while (j >= 0 && brr[j] == 0) {
            j--;
        }

        int i1 = i, j1 = j;
        while (i >= 0 && j >= 0 && arr[i] == brr[j]) {
            i--;
            j--;
        }
        i++;
        j++;

        if (i != j) {
            cout << i << " " << j << endl;
            vector<int> vis(i + 1, 0);
            vector<int> ans = solve(i, vis);
            vector<int> ans2 = solve(j, vis);
            int res=0;
            if(ans2.size()==0){
                vis.resize(i+1,0);
                vis[j]=1;
                ans = solve(i, vis);
                if(ans.size()==0){
                    vis.resize(i+1,0);
                    ans = solve(j, vis);
                    res = (1LL<<i);
                    for(int num: ans){
                        res+=(1LL<<num);
                    }
                }else{
                    res += (1LL<<j);
                    for(int num: ans){
                        res+=(1LL<<num);
                    }
                }
            }else{
                for(int num: ans){
                    res+=(1LL<<num);
                }
                for(int num: ans2){
                    res+=(1LL<<num);
                }
            }
            cout << res << endl;
        }else{

        }
    }
    return 0;
}
