#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int arr[m];
        for(int i=0; i<m; i++)cin >> arr[i];
        unordered_map<int,bool> mp;
        for(int i=0; i<k; i++){
            int temp;
            cin >> temp;
            mp[temp]=true;
        }

        for(int i=0; i<m; i++){
            if(mp.find(arr[i])!=mp.end()){
                if(mp.size()!=n){
                    cout << 0;
                }else{
                    cout << 1;
                }
            }else{
                if(mp.size()>=n-1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
        }
        cout << endl;
    }
}