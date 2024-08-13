#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int t=1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int temp;
    cin >> temp;
    unordered_map<int,bool> mp;
    mp[temp]=1;
    bool flag=true;
    for(int i=1; i<n; i++){
      cin >> temp;
      if(mp.find(temp-1)==mp.end() && mp.find(temp+1)==mp.end()){
        flag=false;
      }
      mp[temp]=1;
    }
    if(flag){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}