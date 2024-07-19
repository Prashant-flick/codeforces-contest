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
        int arr[n];
        map<int,int> mp;
        set<int> st;
        int maxi=INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
            st.insert(arr[i]);
            if(mp[arr[i]]>=2){
                st.erase(st.find(arr[i]));
            }
            maxi = max(maxi,arr[i]);
        }

        if( mp.begin()->first != 0){
            cout << 0 << endl;
            continue;
        }

        auto it2 = mp.begin();
        int temp = it2->first;
        it2++;
        int ans = maxi+1;
        while(it2!=mp.end()){
            // cout << temp << " " << it2->first << endl;
            if(it2->first != temp+1){
                ans = min(temp+1, ans);
                break;
            }
            temp++;
            it2++;
        }
        // cout << ans << endl;

        if(st.size()>1){
            auto it=st.begin();
            it++;
            ans = min(ans, *it);
        }

        cout << ans << endl;
        
    }
    return 0;
}