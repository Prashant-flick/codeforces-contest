#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s[6] = {"BR", "BY", "BG", "RY", "GR", "GY"};

  int t;
  cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    vector<set<int>> vs(6);
    int arr[n+1];
    for(int i=1; i<=n; i++){
      string temp;
      cin >> temp;
      int j=0;
      for(;j<6; j++){
        if(s[j]==temp)break;
      }
      vs[j].insert(i);
      arr[i]=j;
    }

    while(q--){
      int x,y;
      cin >> x >> y;
      if(x>y){
        swap(x,y);
      }
      if(arr[x]!=6-arr[y]-1){
        cout << abs(x-y) << endl;
      }else{
        int ans=1e9;
        for(int i=0; i<6; i++){
          if(arr[x]!=i && arr[y]!=i && vs[i].size()>0){
            auto it1 = vs[i].lower_bound(x);
            auto it2 = vs[i].lower_bound(y);
            if(it1!=vs[i].end()){
              ans=min(ans, abs((*it1)-x)+abs((*it1)-y));
            }else{
              it1--;
              ans=min(ans, abs((*it1)-x)+abs((*it1)-y));
            }
            if(it2!=vs[i].end()){
              if(it2!=vs[i].begin()){
                it2--;
                ans=min(ans, abs((*it2)-x)+abs((*it2)-y));
              }else{
                ans=min(ans, abs((*it2)-x)+abs((*it2)-y));
              }
            }
          }
        }
        if(ans==1e9){
          cout << -1 << endl;
        }else{
          cout << ans << endl;
        }
      }
    }
  }
  
}