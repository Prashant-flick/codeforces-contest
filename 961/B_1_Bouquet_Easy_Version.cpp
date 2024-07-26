#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t=1;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        sort(arr, arr+n);
        int i=0,j=0;
        int sum=0;
        int prev1=arr[0];
        int prev2=arr[0];
        int ans=0;
        while(j<n){
            sum+=arr[j];
            if(sum<=m){
                if(arr[j]-prev1>1){
                    while(arr[i]==prev1){
                        sum-=arr[i];
                        i++;
                    }
                    prev1=prev2;
                }
                if(arr[j]-prev2>1){
                    while(arr[i]==prev2){
                        sum-=arr[i];
                        i++;
                    }
                    prev1=prev2;
                }
                ans=max(ans,sum);
                prev2=arr[j];
                j++;
            }else{
                if(arr[j]-prev1>1){
                    while(arr[i]==prev1){
                        sum-=arr[i];
                        i++;
                    }
                    prev1=prev2;
                }
                if(arr[j]-prev2>1){
                    while(arr[i]==prev2){
                        sum-=arr[i];
                        i++;
                    }
                    prev1=prev2;
                }
                prev2=arr[j];
                while(sum>m){
                    sum-=arr[i];
                    i++;
                }
                j++;
                if(sum<=m){
                    ans=max(sum, ans);
                }
            }
        }

        cout << ans << endl;
    }
}