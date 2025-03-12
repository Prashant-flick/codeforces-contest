#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        if(n==1){
            cout << arr[0] << endl;
            continue;
        }
        int ans=arr[0]+arr[1]-1;
        for(int i=2; i<n; i++){
            ans=ans+arr[i]-1;
        }
        cout << ans << endl;
    }
}