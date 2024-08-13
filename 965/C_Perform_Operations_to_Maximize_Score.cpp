#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int t=1;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)cin >> arr[i];
    vector<pair<int,int>> vec(n);
    for(int i=0; i<n; i++){
      int temp;
      cin >> temp;
      vec[i]=make_pair(arr[i], temp);
    }

    sort(begin(vec), end(vec));
    for (int i = 0; i < n; i++){
      
    }
    
  }
  return 0;
}