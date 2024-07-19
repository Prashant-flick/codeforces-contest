#include <bits/stdc++.h> 
using namespace std; 
#define int long long 

int solve(int *arr, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i]+i > ans){
            ans = arr[i]+i;
        } 
    }
    return ans;
}
 
int32_t main(){  
    int t; 
    cin>>t; 
    while(t--){ 
        int n; 
        cin>>n; 
        int arr[n]; 
        for(int i=0;i<n;i++)cin>>arr[i];

        int ans=solve(arr,n);
        
        cout<<ans<<endl; 
    } 
}
