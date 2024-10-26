#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a >> b;
        if(a>=b){
            cout << a << endl;
            continue;
        }
        int l=1,r=1e9;
        int mid=1;
        int ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if((b-((a-mid)*2))<=mid){
                ans=max(ans,mid);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout << ans << endl;
    }
    
}