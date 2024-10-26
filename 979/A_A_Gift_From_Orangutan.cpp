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
        int maxi=0;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi=max(maxi, arr[i]);
            mini=min(mini, arr[i]);
        }
        cout << (n-1)*(maxi-mini) << endl;
    }
}