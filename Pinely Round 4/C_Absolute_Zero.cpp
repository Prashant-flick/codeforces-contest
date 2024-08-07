#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        bool flag=true;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
          cin >> arr[i];
          if(arr[i]==0){
            flag=false;
          }
          maxi=max(maxi,arr[i]);
          mini=min(mini,arr[i]);
        }

        int ans[40];
        int p=0;
        int cnt=0;
        int i=0;
        flag=false;
        while(i<40){
          int total = maxi+mini;
          total = total/2;
          int j=0;
          if(mini==0){
            if(maxi==0){
              flag=true;
              break;
            }
          }
          ans[p]=total;
          p++;
          maxi=INT_MIN;
          mini=INT_MAX;
          while(j<n){
            arr[j] = abs(arr[j]-total);
            maxi=max(maxi, arr[j]);
            mini=min(mini,arr[j]);
            j++;
          }
          i++;
        }        
        
        if(flag){
          cout << p << endl;
          for(int i=0; i<p; i++){
            cout << ans[i] << " ";
          }
          cout << endl;
        }else{
          cout << -1 << endl;
        }
    }
    return 0;
}