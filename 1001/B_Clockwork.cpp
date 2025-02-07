#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        bool flag=true;
        for(int i=0; i<n; i++){
            if(arr[i]<=(n-i-1)*2 || arr[i]<=i*2){
                flag=false;
                break;
            }
        }
        cout << (flag?"YES":"NO") << endl;
    }
}