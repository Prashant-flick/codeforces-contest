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
        int odd=0;
        int even=0;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
          cin >> arr[i];
          if(arr[i]%2==0){
            even++;
          }else{
            odd++;
          }
          maxi=max(maxi,arr[i]);
        }

        if(even && odd){
          cout << -1 << endl;
          continue;
        }

        if(maxi==0){
          cout << 0 << endl << endl;
          continue;
        }
        int i = 31 - (__builtin_clz(maxi));

        int cnt=0;
        vector<int> ans;
        for(; i>=0; i--){
          for(int j=0; j<n; j++){
            arr[j]=abs(arr[j]-(1<<i));
          }
          ans.push_back((1<<i));
          cnt++;
        }
        for(int i=0; i<n; i++){
          if(arr[i]==1){
            ans.push_back(1);
            cnt++;
            break;
          }
        }
        cout << cnt << endl;
        for(int i=0; i<cnt; i++){
          cout << ans[i] << " ";
        }     
        cout << endl;
    }
    return 0;
}