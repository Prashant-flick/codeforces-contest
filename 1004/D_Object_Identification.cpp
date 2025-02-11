#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n+1];
        int brr[n+1]={0};
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            brr[arr[i]]=i;
        }

        int u=0,v=0;
        for(int i=1; i<=n; i++){
            if(!brr[i]){
                cout << "? " << i << " " << (i==n?1:i+1) << endl;
                cin >> u;
                if(u){
                    cout << "! B" << endl;
                }else{
                    u=1;
                    cout << "! A" << endl;
                }
                break;
            }
        }
        if(u)continue;
        cout << "? " << brr[1] << " " << brr[n] << endl;
        cin >> u;
        if(u<n-1){
            cout << "! A" << endl;
        }else{
            cout << "? " << brr[n] << " " << brr[1] << endl;
            cin >> v;
            if(v==u){
                cout << "! B" << endl;
            }else{
                cout << "! A" << endl;
            }
        }
    }
}