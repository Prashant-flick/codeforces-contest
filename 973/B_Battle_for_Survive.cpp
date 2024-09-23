#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int sum1=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i<n-2){
                sum1+=arr[i];
            }
        }
        cout << (arr[n-1])-(arr[n-2]-sum1) << endl;
    }
}