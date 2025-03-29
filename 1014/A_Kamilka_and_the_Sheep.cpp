#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        int ans=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int diff = abs(arr[i]-arr[j]);
                ans=max(ans,diff);
            }
        }
        cout << ans << endl;
    }
}