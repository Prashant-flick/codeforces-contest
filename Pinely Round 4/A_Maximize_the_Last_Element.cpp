#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        int ans=0;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            if(i%2==0){
                ans=max(ans,temp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}