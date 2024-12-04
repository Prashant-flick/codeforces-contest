#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int x,y,z,k;
        cin >> x >> y >> z >> k;
        int i=1;
        int ans=1e18;
        int diff=0;
        int ans2=0;
        while(i<=z){
            int j=1;
            while(j<=k && i<=z){
                int remh = z-diff;
                int temp = (remh/i) + (remh%i?1:0);
                int res = (i*x)+(temp*y)+ans2;
                ans=min(ans,res);
                i++;
                j++;
            }
            ans2+=y;
            diff+=(i-1);
        }
        cout << ans << endl;
    }
}