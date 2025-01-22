#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353
const int N = 2e5+10;
int dp[2];
int ndp[2];
int arr[N];
int n;

signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)cin >> arr[i];

        dp[0]=1;
        dp[1]=0;
        for(int i=0; i<n; i++){
            ndp[0]=ndp[1]=0;
            for(int j=0; j<2; j++){
                int l;
                if(i==0){
                    l=0;
                }else if(j==0){
                    l=arr[i-1];
                }else if(i==1){
                    l=1;
                }else{
                    l=arr[i-2]+1;
                }
                for(int k=0; k<2; k++){
                    if(k==0 && arr[i]!=l){
                        continue;
                    }
                    if(k==1 && j==1){
                        continue;
                    }
                    ndp[k]=(ndp[k]+dp[j])%MOD;
                }
            }
            dp[0] = ndp[0];
            dp[1] = ndp[1];
            if(ndp[0]==ndp[1] && ndp[0]==0){
                break;
            }
        }
        cout << (dp[0]+dp[1])%MOD << endl;
    }
}