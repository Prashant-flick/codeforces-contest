#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define pb(x) push_back(x)

// const ll INF = 1e15;
// const ll MOD = 998244353;

// ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
// ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
// ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }

// ll pow_mod(ll base, ll p) {
//         if(p == 0)      return 1;
//         ll sqrt_pow = pow_mod(base, p/2);
//         ll ans = mul(sqrt_pow, sqrt_pow);
//         if(p&1) ans = mul(ans, base);
//         return ans;
// }

// vector<int> primes;
// void findPrimes() {
//         ll MAX = 2e5;
//         vector<bool> is_prime(MAX+1, true);
//         for(ll i = 2;i <= MAX;i++) {
//                 if(is_prime[i]) {
//                         primes.push_back(i);
//                         for(ll j = i*i;j <= MAX;j += i)
//                                 is_prime[j] = false;
//                 }
//         }
// }

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m,k,d;
        cin >> n >> m >> k >> d;
        
        int brr[n];
        for(int i=0; i<n; i++){
            int arr[m];
            cin >> arr[0];
            arr[0]++;
            multiset<int> st;
            st.insert(1);
            for(int j=1; j<m; j++){
                cin >> arr[j];
                arr[j] += *st.begin() + 1;
                st.insert(arr[j]);
                if(j-d >= 1){
                    st.erase(st.find(arr[j-d-1]));
                }
            }
            brr[i]=arr[m-1];
        }

        for(int i=1; i<n; i++){
            brr[i]+=brr[i-1];
        }

        int res=brr[k-1];
        for(int i=k; i<n; i++){
            res = min(res, brr[i]-brr[i-k]);
        }
        cout << res << endl;
    }
    return 0;
}