#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int mp[n+1];

    for(int i=2; i<=n; i++){
      int x=1;
      while(x!=i){
        mp[i]=x;
        cout << "? " << i << " " << mp[i] << endl;
        cin >> x;
      }
    }

    cout << "! ";
    for(int i=2; i<=n; i++){
      cout << i << " " << mp[i] << " "; 
    }
    cout << endl;
  }
}