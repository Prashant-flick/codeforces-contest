#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k,x;
        cin >> n >> k >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        sort(arr.rbegin(), arr.rend());
        int sum1=0;
        int sum2=0;
        int i;
        for (i = 0; i < x; i++)
        {
            sum1+=arr[i];
        }
        int j=i;
        while(i<n){
            sum2+=arr[i];
            i++;
        }
        
        int ans=sum2-sum1;
        // if(n==k){
        //     ans=max(ans,0LL);
        // }
        i=0;
        while(j<n && k>0){
            sum1-=arr[i];
            i++;
            sum1+=arr[j];
            sum2-=arr[j];
            j++;
            k--;
            ans=max(ans,sum2-sum1);
        }
        while(i<n && k>0){
            sum1-=arr[i];
            i++;
            k--;
            ans=max(ans,sum2-sum1);
        }
        cout << ans << endl;
    }
    
    return 0;
}