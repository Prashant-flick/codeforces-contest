#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0]==s[n-1]){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
}