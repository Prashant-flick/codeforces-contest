#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int sum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
        }

        

        sort(arr, arr+n);
        int mid = arr[n/2];
        if(mid*2*n<sum){
            cout << 0 << endl;
        }else{
            if(n<3){
                cout << -1 << endl;
                continue;
            }
            int ans = (mid*2*n)-sum;
            cout << ans+1 << endl;
        }
    }
}