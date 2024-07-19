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
        int n,k;
        cin >> n >> k;
        int arr[2*n];
        map<int,int> mp1;
        set<int> st;
        map<int,int> mp2;
        for(int i = 0; i <n; i++) {
            cin >> arr[i];
            st.insert(arr[i]);
            mp1[arr[i]]++;
            if(mp1[arr[i]]==2){
                st.erase(st.find(arr[i]));
            }
        }
        for(int i = n; i<2*n; i++){
            cin >> arr[i];
            mp2[arr[i]]++;
        }

        auto it1 = mp1.begin();
        int p=2*k;
        while(it1!=mp1.end() && p){
            if(it1->second == 2){
                cout << it1->first << " " << it1->first << " ";
                p-=2;
            }
            it1++;
        }
        auto it3 = st.begin();
        while(p && it3!=st.end()){
            cout << *it3 << " ";
            it3++;
            p--;
        }
        cout << endl;

        auto it2 = mp2.begin();
        p=2*k;
        while(p && it2!=mp2.end()){
            if(it2->second == 2){
                cout << it2->first << " " << it2->first << " ";
                p-=2;
            }
            it2++;
        }
        it3 = st.begin();
        while(p && it3!=st.end()){
            cout << *it3 << " ";
            it3++;
            p--;
        }
        cout << endl;
    }
    return 0;
}