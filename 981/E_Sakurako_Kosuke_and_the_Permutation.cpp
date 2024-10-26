#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve(int *arr, int i, int *vis){
    if(vis[i]){
        return 0;
    }
    vis[i]=1;
    return 1 + solve(arr, arr[i], vis);
}

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr[i]--;
        }

        int vis[n]={0};
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int cnt=solve(arr, i, vis);
                ans+=(cnt-1)/2;
            }
        }
        cout << ans << endl;
    }
}