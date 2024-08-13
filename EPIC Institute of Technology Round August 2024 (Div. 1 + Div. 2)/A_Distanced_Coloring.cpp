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
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(a,c)*min(b,c) << endl;
  }
  

}