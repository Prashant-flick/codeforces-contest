#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int dp[n]={0};
        int j=n-1, i=n-1;
        int sum=0;
        int cnt=0;
        while(j>=0){
            sum+=arr[j];
            if(sum<=k){
                cnt++;
                dp[j]=cnt;
                j--;
            }else{
                cnt++;
                while(sum>k){
                    sum-=arr[i];
                    i--;
                    cnt--;
                }
                dp[j]=cnt;
                j--;
            }
        }

        int ans=dp[n-1];
        for(i=n-2; i>=0; i--){
            if(dp[i]!=0 && i+dp[i]+1<n){
                dp[i]+=dp[i+dp[i]+1];
            }
            dp[i]=max(dp[i], dp[i+1]);
            ans+=dp[i];
        }

        // for(int i=0; i<n; i++){
        //     cout << dp[i] << " ";
        // }
        cout << ans << endl;
    }
    return 0;
}