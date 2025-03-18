#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        if(n==2){
            cout << arr[0]+arr[1] << endl;
            continue;
        }
        if(k==1){
            int maxi=0;
            for(int i=1; i<n-1; i++)maxi=max(maxi,arr[i]);
            cout << max(maxi+arr[0], max(maxi+arr[n-1], arr[0]+arr[n-1])) << endl;
            continue;
        }
        sort(arr,arr+n);
        int ans=0;
        for(int i=n-1; i>=n-k-1; i--){
            ans+=arr[i];
        }
        cout << ans << endl;
    }
}