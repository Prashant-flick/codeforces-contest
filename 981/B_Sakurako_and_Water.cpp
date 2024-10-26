#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> arr[i][j];
            }
        }

        int ans=0;
        for(int i=n; i>0; i--){
            int j=i;
            int k=1;
            int mini=0;
            while(j<=n){
                mini=min(mini, arr[j][k]);
                j++;
                k++;
            }
            // cout << i << " " << mini << endl;
            ans+=abs(mini);
        }

        for(int i=2; i<=n; i++){
            int j=i;
            int k=1;
            int mini=0;
            while(j<=n){
                mini=min(mini, arr[k][j]);
                j++;
                k++;
            }
            // cout << i << " " << mini << endl;
            ans+=abs(mini);
        }
        cout << ans << endl;

    }
}