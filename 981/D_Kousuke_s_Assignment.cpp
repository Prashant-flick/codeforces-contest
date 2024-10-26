#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==0 || mp[sum]==1){
                ans++;
                mp.clear();
                sum=0;
                continue;
            }
            mp[sum]=1;
        }
        cout << ans << endl;
    }
}