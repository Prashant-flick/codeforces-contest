#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        int arr[n];
        int tot=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            tot+=arr[i];
        }
        sort(arr, arr+n);
        int ans=0;
        int j=1;
        for(int i=n-1; i>0; i--){
            int temp = tot-arr[i];
            if(temp>0 && temp>x){
                int a = temp-x;
                int b = temp-y;
                // if(b>arr[i]){
                //     j++;
                //     continue;
                // }
                // if(a>arr[i]){
                //     int bi = lower_bound(arr, arr+(n-j), b) - arr;
                //     ans+=(i-bi);
                //     j++;
                //     continue;
                // }
                int ai = upper_bound(arr, arr+(n-j), a) - arr;
                int bi = lower_bound(arr, arr+(n-j), b) - arr;
                if(ai!=0){
                    ai--;
                }
                if(ai==bi && (temp-arr[ai]<x || temp-arr[ai]>y)){
                    j++;
                    continue;
                }
                // cout << ai << " " << bi << endl;
                ans+=(ai-bi)+1;
                j++;
                continue;
            }
            j++;
        }
        cout << ans << endl;
    }
}