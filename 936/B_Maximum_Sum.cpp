#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int32_t main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int arr[n];
        int totsum=0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            totsum+=(mod+arr[i])%mod;
        }

        int j=0;
        int sum=0;
        int maxsum=INT_MIN;
        while(j<n){
            sum+=arr[j];
            if(sum>=0){
                maxsum=max(maxsum,sum);
            }else if(sum<0){
                sum=0;
            }
            j++;
        }

        int ans=maxsum;
        if(ans>0){
            while(k--){
                ans+=(mod+ans)%mod;
            }
            ans = (totsum-maxsum)+ans;
            cout << (mod+ans)%mod << endl;
        }else{
            cout << (mod+totsum)%mod << endl;
        }

        
    }
}