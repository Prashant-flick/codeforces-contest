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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> brr(n);
    for(int i=0; i<n; i++)cin >> arr[i];
    for(int i=0; i<n; i++)cin >> brr[i];
    bool flag=true;
    // int i1=0;
    // int j1=n-1;
    // int i2=0;
    // int j2=n-1;
    // while(i1<j1 && i2<j2){
    //   if((arr[i1]==brr[i2] || arr[i1]==brr[j2]) && (arr[j1]==brr[j1] || arr[j1]==brr[j2])){
    //     i1++;i2++;
    //     j1--;j2--;
    //   }else{
    //     flag=false;
    //     break;
    //   }
    // }
    if(arr==brr){
      cout << "Bob" << endl;
      continue;
    }
    reverse(begin(brr), end(brr));
    if(arr==brr){
      cout << "Bob" << endl;
    }else{
      cout << "Alice" << endl;
    }
  }
  

}