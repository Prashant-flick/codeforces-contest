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
        string s;
        cin >> s;
        string map = "map";
        string pie = "pie";
        
        if(n < 3 || ((s.find(map) == string::npos) && (s.find(pie) == string::npos)) ){
            cout << 0 << endl;
            continue;
        }

        string temp = "";
        temp+=s[0];
        temp+=s[1];
        temp+=s[2];
        int ans=0;
        for(int i=3; i<=n; i++){
            if(temp=="map" || temp=="pie"){
                ans++;
                if(i<n-1 && temp=="map"){
                    if(s[i]=='i' && s[i+1]=='e'){
                        temp="ie";
                        if(i!=n-2)temp+=s[i+2];
                        i++;
                        continue;
                    }
                }
                temp.erase(1,1);
                if(i!=n)temp+=s[i];
            }else{
                temp.erase(0,1);
                if(i!=n)temp+=s[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}