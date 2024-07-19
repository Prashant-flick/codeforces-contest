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
        int n,m,x;
        cin >> n >> m >> x;
        
        set<int> ans;
        ans.insert(x);
        for(int i=0; i<m; i++){
            int d;
            cin >> d;
            char ch;
            cin >> ch;
            set<int> st=ans;
            auto it=st.begin();
            ans.clear();
            while(it!=st.end()){
                if(ch=='0'){
                    int a = (*it+d)%n;
                    if(a==0)a=n;
                    ans.insert(a);
                    it++;
                }else if(ch=='1'){
                    int a = ((*it-d)+n)%n;
                    if(a==0)a=n;
                    ans.insert(a);
                    it++;
                }else{
                    int a = (*it+d)%n;
                    int b = ((*it-d)+n)%n;
                    if(b==0)b=n;
                    if(a==0)a=n;
                    ans.insert(a);
                    ans.insert(b);
                    it++;
                }
            }
        }

        cout << ans.size() << endl;
        auto it = ans.begin();
        while(it!=ans.end()){
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
    return 0;
}