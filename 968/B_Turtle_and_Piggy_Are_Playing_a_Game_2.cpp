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
    int arr[n];
    for(int i=0; i<n; i++)cin >> arr[i];
    sort(arr,arr+n);
    cout << arr[n/2] << endl;
  }
}