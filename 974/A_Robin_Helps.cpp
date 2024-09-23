#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        int sum=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(arr[i]>=k){
                sum+=arr[i];
                continue;
            }
            if(arr[i]==0 && sum!=0){
                sum--;
                ans++;
            }
        }
        cout << ans << endl;
    }
}