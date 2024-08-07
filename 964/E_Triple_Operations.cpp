#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int cnt1 = 0;
        int cnt2 = 0;
        int k=l;
        int k1=l+1;
        while(k){
          cnt1++;
          k/=3;
        }
        while(k1){
          cnt2++;
          k1/=3;
        }

        int ans = 0;

        if (cnt2 <= cnt1) {
            ans = cnt2 + (cnt1 + cnt2);
            int j=l+2;
            if(pow(3,cnt2)<=j)cnt2++;
            int cnt3=cnt2;
            int cnt4=pow(3,cnt3);

            if(j<=r && j!=cnt4){
    
              if(cnt4>r){
                ans+=(cnt3*(r-j+1));
              }else{
                ans+=(cnt3*(cnt4-j));
                cnt3++;
                j=cnt4;
                cnt4*=3;
                  if(cnt4>r){
                  ans+=(cnt3*(r-j+1));
                }
              }
            }
            while(cnt4 <= r) {
              ans+=(cnt3*(cnt4-j));
              j*=3;
              cnt4*=3;
              cnt3++;
              if(cnt4>r){
                ans+=(cnt3*(r-j+1));
              }
            }
        } else {
            ans = cnt1 + (cnt1 + cnt2);
            int j=l+2;
            if(pow(3,cnt2)<=j)cnt2++;
            int cnt3=cnt2;
            int cnt4=pow(3,cnt3);

            if(j<=r && j!=cnt4){
              if(cnt4>r){
                ans+=(cnt3*(r-j+1));
              }else{
                ans+=(cnt3*(cnt4-j));
                cnt3++;
                j=cnt4;
                cnt4*=3;
                if(cnt4>r){
                  ans+=(cnt3*(r-j+1));
                }
              }
            }
            while(cnt4 <= r) {
              ans+=(cnt3*(cnt4-j));
              j*=3;
              cnt4*=3;
              cnt3++;
              if(cnt4>r){
                ans+=(cnt3*(r-j+1));
              }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
