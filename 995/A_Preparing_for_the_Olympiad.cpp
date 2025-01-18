#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n],brr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<n; i++)cin >> brr[i];
        int ans=arr[n-1];
        for(int i=0; i<n-1; i++){
            if(arr[i]-brr[i+1]>0){
                ans+=arr[i]-brr[i+1];
            }
        }
        cout << ans << endl;
    }
}