#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int g=0,b=0;
        for(int i=0; i<n; i++){
            if(mp.find(arr[i])==mp.end()){
                continue;
            }
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            if(mp.find(k-arr[i])!=mp.end()){
                g+=2;
                mp[k-arr[i]]--;
                if(mp[k-arr[i]]==0){
                    mp.erase(k-arr[i]);
                }
            }else{
                b++;
            }
        }

        cout << g/2 << endl;

    }
}