#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;   
        int l=1,r=1e9+10;
        int mid = (l+r)/2LL;
        bool flag=false;
        while(l<=r){
            mid = (l+r)/2LL;
            int value = (mid*mid)-mid;
            if(value==n){
                l=r=mid;
                flag=true;
                break;
            }else if(value<n){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        
        l=r;
        int val = l*l;
        int ans = val + (n-(val-l));
        if(flag){
            cout << ans-1 << endl;
            continue;
        }
        cout << ans << endl;
    }
}