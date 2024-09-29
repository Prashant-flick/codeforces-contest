#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int tot=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            tot+=arr[i];
            maxi=max(maxi,arr[i]);
        }

        int ans=1;
        int i=n;
        while(i>1){
            if((tot<=maxi*i && (maxi*i)-tot<=k) || (tot>maxi*i && (i-(tot-maxi*i)%i)%i<=k)){
                ans=i;
                break;
            }
            i--;
        }

        cout << ans << endl;
    }
    
    
}