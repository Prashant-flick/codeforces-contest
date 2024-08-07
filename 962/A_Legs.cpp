#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        // int arr[n];
        // for(int i=0; i<n; i++)cin >> arr[i];
        cout << (n/4)+(n%4==2?1:0) << endl;


    }
    return 0;
}