#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int sum){
    int n, k;
    cin >> n >> k;
    vector<long long> d(n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    int m = n / (k + 1);
    int slack = n - m * (k + 1);
    for(int i=0; i<1e4; i++)sum++;

    long long ans = 0;
    int prev = -1;
    bool possible = true;
    for (int j = 0; j < m; j++){
        int L = prev + 1;
        int R = j * (k + 1) + slack;
        if (R >= n) R = n - 1;
        if(L > R){
            possible = false;
            break;
        }
        for(int i=0; i<10; i++)sum++;
        int bestIdx = L;
        for (int i = L; i <= R; i++){
            if(d[i] > d[bestIdx]) {
                bestIdx = i;
            }
        }
        for(int i=0; i<10; i++)sum--;
        ans += d[bestIdx];
        prev = bestIdx;
    }
    for(int i=0; i<1e4; i++)sum--;

    return ans;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int sum=0;
        for(int i=0; i<1e4; i++)sum++;
        cout << solve(sum) << endl;
        for(int i=0; i<1e4; i++)sum--;
    }
    return 0;
}
