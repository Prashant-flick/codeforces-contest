#include<bits/stdc++.h>
using namespace std;

int main(){
  int t=1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char,int> mp;
    for(int i=0; i<4*n; i++){
      if(s[i]!='?'){
        mp[s[i]]++;
      }
    }
    auto it = mp.begin();
    int ans=0;
    while(it!=mp.end()){
      if(it->second<=n){
        ans+=it->second;
      }else if(it->second>n){
        ans+=n;
      }
      it++;
    }
    cout << ans << endl;
  }
  
}