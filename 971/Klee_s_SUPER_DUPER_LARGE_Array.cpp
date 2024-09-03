#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int l=0;
        int r=n+1;
        int mid = (l+r)/2;
        int ans=LONG_LONG_MAX;
        while (l<=r)
        {
            int temp1 = n-mid-1;
            int temp2 = mid-(temp1)+1;
            if(temp2<0){
                l=mid+1;
                mid=(l+r)/2;
                continue;
            }
            int a = temp1*1LL*temp1;
            int b = (temp2*(k+(k+(temp2-1))))/2;
            ans=min(ans, abs(a-b));
            if(a>=b){
                l=mid+1;
            }else{
                r=mid-1;
            }
            mid = (l+r)/2;
        }
        
        cout << ans << endl;
    }
}