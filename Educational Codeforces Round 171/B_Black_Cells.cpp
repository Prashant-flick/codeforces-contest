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
        int maxi1=1;
        int maxi2=1;
        for(int i=0;i<n; i++){
            cin >> arr[i];
        }

        int brr[n-1];   uhbnuh0i   ug4
        for(int i=1; i<n; i++){
            if(i%2!=0){
                maxi1=max(maxi1, arr[i]-arr[i-1]);
            }else{
                maxi2=max(maxi2, arr[i]-arr[i-1]);
            }
        }

        if(n%2==0){
            cout << maxi1 << endl;
            continue;
        }
        cout << min(maxi1, maxi2) << endl;
    }
}