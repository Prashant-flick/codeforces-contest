#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while ((t--))
  {
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    for(int i=0; i<n; i++){
      int u,v;
      cin >> u >> v;
      vec.push_back({u,v});
    }

    int xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;
    int dist = (xs-xt)*(xs-xt)+0LL+(ys-yt)*(ys-yt);
    
    bool flag=true;
    for(auto &it: vec){
      int x=it.first;
      int y=it.second;
      int dist2 = (x-xt)*1LL*(x-xt)+0LL+(y-yt)*1LL*(y-yt);
      if(dist2<=dist){
        flag=false;
        break;
      }
    }

    if(flag){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  

}