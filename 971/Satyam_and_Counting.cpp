#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt3[n+1][2]={0};
        int cnt[n+1]={0};
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            cnt[x]++;
            cnt3[x][y]=1;
        }

        int ans=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0; i<=n; i++){
            if(cnt[i]==2){
                ans+=cnt1;
                cnt1+=4;
                cnt2++;
            }
            if(i!=0 && i!=n){
                if(cnt3[i-1][0]==1 && cnt3[i+1][0]==1 && cnt3[i][1]==1){
                    ans++;
                }
                if(cnt3[i-1][1]==1 && cnt3[i+1][1]==1 && cnt3[i][0]==1){
                    ans++;
                }
            }
        }
        // cout << ans << endl;
        for(int i=0; i<=n; i++){
            if(cnt[i]==1){
                ans+=cnt2;
            }
        }
        cout << ans << endl;
    }
}