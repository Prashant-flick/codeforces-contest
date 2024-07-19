#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define pb(x) push_back(x)

const ll INF = 1e15;
const ll MOD = 998244353;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }

ll pow_mod(ll base, ll p) {
        if(p == 0)      return 1;
        ll sqrt_pow = pow_mod(base, p/2);
        ll ans = mul(sqrt_pow, sqrt_pow);
        if(p&1) ans = mul(ans, base);
        return ans;
}

vector<int> primes;
void findPrimes() {
        ll MAX = 2e5;
        vector<bool> is_prime(MAX+1, true);
        for(ll i = 2;i <= MAX;i++) {
                if(is_prime[i]) {
                        primes.push_back(i);
                        for(ll j = i*i;j <= MAX;j += i)
                                is_prime[j] = false;
                }
        }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s1;
        string s2;
        cin >> s1 >> s2;
        if(n%2!=0 || s2[n-2]!='>'){
            cout << "NO" << endl;
            continue;
        }
        map<int,int> mp;

        bool flag=true;
        int mini2=-1;
        bool flag3=false;
        for(int i=0; i<n-1; i+=2) {
            if(s2[i]=='>'){
                flag3=true;
                if(i==n-2){
                    mp[mini2]=i+1;
                }
            }else{
                flag=false;
                if(flag3){
                    if(mini2!=i-1){
                        mp[mini2]=i-1;
                    }
                }
                mini2=i+1;
                flag3=false;
            }
        }
        if(flag){
            cout << "YES" << endl;
            continue;
        }
        flag=true;
        mini2=0;
        bool flag2=false;
        for(int i=1; i<n-2; i+=2) {
            if(s1[i]=='>'){
                flag2=true;
                if(i==n-3){
                    mp[mini2]=i+1;
                }
            }else{
                flag=false;
                if(flag2){
                    mp[mini2]=i-1;
                }
                mini2=i+1;
                flag2=false;
            }
        }
        
        if(flag){
            cout << "YES" << endl;
        }else{
            if(mp.size()<2){
                cout << "NO" << endl;
                continue;
            }
            auto it = mp.begin();
            if(it->first > 1){
                cout << "NO" << endl;
                continue;
            }
            int temp=it->second;
            // cout << it->first << " " << it->second << endl;
            it++;
            flag=true;
            while(it != mp.end()) {
                // cout << it->first << " " << it->second << endl;
                if(it->first >= temp){
                    flag=false;
                    break;
                }
                temp=max(temp,it->second);
                it++;
            }
            if(flag && temp>=n-1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}