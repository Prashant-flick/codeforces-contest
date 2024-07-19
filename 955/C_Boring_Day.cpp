#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        int i=0,j=0;
        int sum=0;
        int ans=0;
        
        while(j<n){
            sum+=arr[j];
            while(sum>r){
                sum-=arr[i]; 
                i++;
            }
            if(sum>=l && sum<=r){
                sum=0; 
                ans++; 
                i=j+1;
            }
            j++;
        }

        cout << ans << endl;
    }
}