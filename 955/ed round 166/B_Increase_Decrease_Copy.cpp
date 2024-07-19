#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int brr[n+1];
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<=n; i++)cin >> brr[i];

        int mini=INT_MAX;
        int ans=1;
        for(int i=0; i<n; i++){
            int sum = abs(arr[i]-brr[n]) + abs(brr[n]-brr[i]);
            int sum2 = abs(arr[i]-brr[i]);
            ans+=sum2;
            mini = min(mini, min(abs(sum-sum2),abs(brr[n]-arr[i])));
            mini = min(mini, abs((brr[n]-arr[i])-(brr[i]-arr[i])));
        }

        ans+=mini;
        cout << ans << endl;
    }
    
}