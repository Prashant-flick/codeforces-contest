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
    int n;
    cin >> n;
    int arr[n];
    int even=0;
    int odd=0;
    int maxieven=0;
    int maxiodd=0;
    for(int i=0;i<n; i++){
      cin >> arr[i];
      if(arr[i]%2==0){
        even++;
        maxieven=max(maxieven, arr[i]);
      }else{
        odd++;
        maxiodd=max(maxiodd, arr[i]);
      }
    }
    if(even==0 || odd==0){
      cout << 0 << endl;
    }else{
      sort(arr, arr+n);
      if(arr[n-1]%2!=0){
        cout << even << endl;
      }else{
        int cnt=0;
        bool flag=true;
        for(int i=0; i<n; i++){
          if(arr[i]%2==0){
            if(arr[i]<maxiodd){
              maxiodd = arr[i]+maxiodd;
              cnt++;
            }else{
              flag=false;
              break;
            }
          }
        }

        if(flag){
          cout << cnt << endl;
        }else{
          cout << even+1 << endl;
        }
      }
    } 
  }
  
}