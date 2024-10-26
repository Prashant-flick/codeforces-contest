#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        sort(arr, arr+n);

        int ans=0;
        int cnt=0;
        for(int i=0; i<n && k>0; i++){
            int p = arr[i]-cnt;
            if(p>0){
                if((p*(n-i))>=k){
                    ans+=k;
                    k=0;
                    break;
                }else{
                    ans+=(p*(n-i));
                    k-=(p*(n-i));
                }
                
            }
            cnt=arr[i];
            ans++;
        }
        cout << ans << endl;
    }
    
}