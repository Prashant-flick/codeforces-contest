#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n][2];
        int maxi1=0;
        int maxi2=0;
        for(int i=0; i<n; i++){
            cin >> arr[i][0] >> arr[i][1];
            maxi1=max(maxi1, arr[i][0]);
            maxi2=max(maxi2, arr[i][1]);
        }
        cout << (maxi1+maxi2)*2 << endl;
    }
}