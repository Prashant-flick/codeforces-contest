#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t=1;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int arr[n];
    int maxi=INT_MIN;
    for(int i=0;i<n; i++){
      cin >> arr[i];
      maxi=max(maxi, arr[i]);
    }

    for(int i=0; i<n; i++){
      arr[i]+=(maxi+k-1-arr[i])/(k*2)*k*2;
    }

    sort(arr, arr+n);
    if(arr[0]+k<=arr[n-1]){
      cout << -1 << endl;
    }else{
      cout << arr[n-1] << endl;
    }
  }
  
}