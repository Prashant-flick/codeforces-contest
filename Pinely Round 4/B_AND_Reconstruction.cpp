#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        int ans=0;
        int brr[n-1];
        for(int i=0; i<n-1; i++)cin >> brr[i];

        int arr[n];
        arr[0]=brr[0];
        bool flag=true;
        for(int i=1; i<n; i++){
          if(i==n-1){
            arr[i]=brr[i-1];
          }else{
            arr[i]=(brr[i-1]|brr[i]);
          }
          if((arr[i]&arr[i-1])!=brr[i-1]){
            flag=false;
            break;
          }
        }

        if(flag){
          for(int i=0; i<n; i++){
            cout << arr[i] << " ";
          }
          cout << endl;
        }else{
          cout << -1 << endl;
        }
    }
    return 0;
}