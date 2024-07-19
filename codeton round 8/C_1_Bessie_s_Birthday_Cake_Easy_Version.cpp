#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        int ans=x-2;
        int arr[x];
        for(int i=0; i<x; i++){
            cin >> arr[i];
        }

        sort(arr, arr+x);
        for(int i=0; i<x-1; i++){
            if(arr[i+1]-arr[i]==2){
                ans++;
            }
        }
        if(((arr[x-1]+2)%n) == arr[0]){
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}