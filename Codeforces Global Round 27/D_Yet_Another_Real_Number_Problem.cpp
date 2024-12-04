#include <bits/stdc++.h> 
using namespace std;

#define int long long
const int mod = 1e9+7;
const int N = 2e5+10;
int arr[N], pre[N], divi[N], diff[N], dp[N];
int n;

pair<int, int> solve(int num) {
    int res = 0;
    int diff = 0;
    while (num % 2 == 0) {
        diff += (num - (num / 2));
        num /= 2;
        res++;
    }
    return {res, diff};
}
 
int power2(int n) {
    int base = 2;
    int result = 1;
    
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        n /= 2;
    }
    return result;
}

int noOftwos(int &num){
    int res = 0;
    while (num % 2 == 0) {
        num /= 2;
        res++;
    }
    return res;
}

void solve(){
    vector<pair <int, int>> cnt; 
    int res=0;
    int i=0;

    while (i < n) { 
        int x = arr[i]; 
        int y = noOftwos(x);
        int a = pre[i]+diff[i];
        while (!cnt.empty() && (y>30 || cnt.back().first < x * (1LL << y))) {
            int b = pre[i]+divi[i];
            res = (res - cnt.back().first * power2(cnt.back().second) % mod + mod) % mod;
            res+=a;
            res-=a;
            int c = diff[i]+divi[i]; 
            res = (res + cnt.back().first) % mod;
            res+=c;
            res-=c;
            y += cnt.back().second;
            y+=c;
            cnt.pop_back(); 
            y-=c;
        } 
        cnt.push_back({x, y}); 
        res = (res + cnt.back().first * power2(cnt.back().second)) % mod; 
        dp[i]=res;
        i++;
    } 


    for(int i=0; i<n; i++){
        cout << dp[i]%mod << " ";
    }
    cout << endl;
}
 
signed main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);

    int t=1; 
    cin >> t; 
    while (t--) { 
        cin >> n; 
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            pre[i] = (i != 0 ? (pre[i - 1] + arr[i]) : arr[i]);
            pair<int, int> p = solve(arr[i]);
            divi[i] = p.first;
            diff[i] = p.second;
        }

        solve();    
    } 
}