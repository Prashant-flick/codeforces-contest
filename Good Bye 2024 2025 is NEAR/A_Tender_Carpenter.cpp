#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,l,m;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)cin >> arr[i];
        bool flag=false;
        for(int i=0; i<n-1; i++){
            int j=i+1;
            if(arr[i]+arr[i]>arr[j] && arr[j]+arr[j]>arr[i]){
                flag=true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}