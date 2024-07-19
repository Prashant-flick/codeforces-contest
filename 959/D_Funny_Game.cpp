// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// // int dp[100001];

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int t=1;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; i++)cin >> arr[i];

//         vector<pair<int,int>> ans(n-1);
//         int vis[n]={0};
//         bool flag=true;
//         for(int i=n-1; i>0; i--){
//             vector<int> check(i,-1);
//             bool flag1=false;
//             for(int j=0; j<n; j++){
//                 if(vis[j])continue;
//                 int x = arr[j]%i;
//                 if(check[x]==-1){
//                     check[x]=j;
//                 }else{
//                     ans[i-1]={j,check[x]};
//                     flag1=true;
//                     vis[j]=1;
//                     break;
//                 }
//             }

//             if(!flag1){
//                 flag=false;
//                 break;
//             }
//         }
        
//         if(!flag){
//             cout << "NO" << endl;
//         }else{
//             cout << "YES" << endl;
//             for(auto &it: ans){
//                 cout << it.first+1 << " " << it.second+1 << endl;
//             }
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define vpll vector<pair<ll, ll>>
#define ll long long
#define vll vector<ll>
#define lire(v) for (auto &u : v) cin >> u;
#define ff first
#define ss second

const ll MAXN = 2e5+2;
const ll LOG =18; // log2(MAXN)+1
vll adj[MAXN]; 
vpll edges[MAXN];
ll up[MAXN][LOG]; // up[v][j] is the 2^j-th Ac of node v
ll sez[MAXN];
ll st[MAXN];
ll en[MAXN];
ll timer = 0;
 
bool est_premier(ll n){
    if(n<=1) return false;
    if(n<=3) return true;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
 
struct DSU {
    vll sz, parent;
 
    // Initialize DSU with 'n' elements
    void Init(ll n) {
        // Resize the vectors to hold 'n' elements
        sz.resize(n);
        parent.resize(n);
        // Initialize each element to be its own parent (each element is its own set)
        for (ll i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1; // Each set initially has a size of 1
        }
    }
 
    // Find the root of the set containing 'u' with path compression
    ll get(ll u) {
        // If 'u' is not its own parent, recursively find the root and compress the path
        return (parent[u] == u) ? u : (parent[u] = get(parent[u]));
    }
 
    // Union the sets containing 'u' and 'v'
    bool unite(ll u,ll v) {
        // Find the roots of the sets containing 'u' and 'v'
        u = get(u);
        v = get(v);
        // If they are already in the same set, return false
        if (u == v) return false;
        // Union by size: attach the smaller tree under the root of the larger tree
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u; // Make 'u' the parent of 'v'
        sz[u] += sz[v]; // Update the size of the root
        return true; // Indicate that a union was performed
    }
 
    // Check if 'u' and 'v' are in the same set
    bool same_set(ll u,ll v) {
        return get(u) == get(v);
    }
 
    // Get the size of the set containing 'u'
    ll size(ll u) {
        return sz[get(u)];
    }
};
 
 
void sol() 
{
   ll n;cin>>n;
   vll a(n);
   lire(a);
   DSU dsu;
   dsu.Init(n+3);
   vector<vector<vll>> groups(n,vector<vll>(n));
   for(ll i=0;i<n;i++){
      for(ll k=1;k<n;k++){
         ll r=a[i]%k;
         groups[k][r].push_back(i+1);
      }
   }
   vpll vp;
   for(ll i=n-1;i>=1;i--){
      bool test=false;
      for(ll j=n-1;j>=0&&!test;j--){
          ll res=a[j]%i;
          while (!groups[i][res].empty())
          {
              ll nv=groups[i][res].back();
              groups[i][res].pop_back();
              if(dsu.same_set(nv,j+1)) continue;
              test=true;
              dsu.unite(nv,j+1);
              vp.push_back({nv,j+1});
              break;
          }
          
      }
   }
    reverse(all(vp));
    cout << "YES" << endl;
    for(auto p:vp) cout<<p.ff<<" "<<p.ss<<endl;
}
signed main() {
    ll ttt= 1;
    cin >>ttt;
    ////precompute();
    while (ttt--) {
        sol();
    }
    return 0;
}