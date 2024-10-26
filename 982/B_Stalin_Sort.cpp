#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        int ans=n-1;
        for(int i=0; i<n; i++){
            int cnt=i;
            for(int j=i+1; j<n; j++){
                if(arr[j]>arr[i])cnt++;
            }
            ans=min(ans,cnt);
        }
        cout << ans << endl;
    }
}