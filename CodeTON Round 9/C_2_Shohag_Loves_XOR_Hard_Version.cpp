#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int x,m;
        cin >> x >> m;
        int ans=0;
        unordered_map<int,bool> checked;

        for(int i=1; i<=m; i++){
            if(i<=m && ((i^x)%i==0 || ((i^x)%x)==0)){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}