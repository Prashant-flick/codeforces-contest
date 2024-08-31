#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+5;
int dp[N];
int vis[N];

int dfs(unordered_map<int,vector<int>> &mp, int i){
  if(mp.find(i)==mp.end())return 0;
  if(dp[i]!=-1)return dp[i];
  vis[i]=1;
  int maxi=0;
  for(int &v: mp[i]){
    if(!vis[v]){
      maxi = max(dp[i], max(v,dfs(mp, v)));
    }
  }
  return dp[i]=max(dp[i], maxi);
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    unordered_map<int,vector<int>> mp;
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
      int n1;
      cin >> n1;
      set<int> st;
      for(int j=0; j<n1; j++){
        int temp;
        cin>> temp;
        st.insert(temp);
      }
      int f=-1;
      int s=-1;
      int k=0;
      auto it = st.begin();
      while(it!=st.end()){
        if((*it)!=k){
          if(f!=-1){
            s=k;
            break;
          }
          f=k;
          if(k+1==(*it)){
            k+=2;
          }else{
            s=k+1;
            break;
          }
        }else{
          k++;
        }
        it++;
      }
      if(s==-1){
        s=k;
      }
      mp[f].push_back(s);
      maxi=max(maxi, s);
    }
    memset(dp, -1, sizeof dp);
    memset(vis, 0, sizeof vis);
    int ans=0;
    for(int i=0; i<=min(maxi,m); i++){
      int res = dfs(mp, i);
      cout << res << endl;
      ans+=max(res, i);
    }
    if(min(maxi,m)!=m){
      ans = ans+(((m-maxi)*(maxi+m+1)/2));
    }
    cout << ans << endl;
  }
}