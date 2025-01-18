#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,x,y,m;
        cin >> n >> m;
        int sum=4*m;
        int ans=0;
        for(int i=0; i<n; i++){
            cin >> x >> y;
            if(i==0){
                ans+=sum;
            }else{
                ans-=2*(2*m-(x+y));
                ans+=sum;
            }
        }
        cout << ans << endl;
    }
}