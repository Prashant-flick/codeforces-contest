#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        unordered_map<int,pair<int,int>> mp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr[i]%=k;
            mp[arr[i]].first=i;
            mp[arr[i]].second++;
        }
        bool flag=false;
        for(auto it: mp){
            if(it.second.second==1){
                cout << "YES" << endl;
                cout << it.second.first+1 << endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout << "NO" << endl;
        }
    }
}