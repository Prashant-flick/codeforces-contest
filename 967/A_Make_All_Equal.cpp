#include<bits/stdc++.h>
using namespace std;

int main(){
  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    int maxi=0;
    for(int i=0; i<n; i++){
      int temp;
      cin >> temp;
      mp[temp]++;
      maxi=max(maxi, mp[temp]);
    }
    cout << n-maxi << endl;
  }
}