#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int ans=0;
    while(n){
      ans+=n%10;
      n/=10;
    }
    cout << ans << endl;
  }
  
}