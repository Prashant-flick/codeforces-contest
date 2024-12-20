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
        int ans=0;
        int i=0;
        while(i<n){
            while(i<n && arr[i]==0){
                i++;
            }
            if(i==n)break;
            while(i<n && arr[i]!=0){
                i++;
            }
            ans++;
        }
        if(ans>2){
            ans=2;
        }
        cout << ans << endl;
    }
}