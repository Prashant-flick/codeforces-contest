#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)cin >> arr[i];

        int ans=0;
        bool flag=true;
        int last=0;
        for(int i=1; i<n; i++){
            int a1 = arr[i-1], a2 = arr[i];
            if(a2==1 && a1>1){
                flag=false;
                break;
            }
            int cnt1=0,cnt2=0;
            while(a2<a1){
                a2*=a2;
                cnt1++;
            }

            while(a1*a1<=a2){
                if(a1==1){
                    cnt2=-1;
                    break;
                }
                a1*=a1;
                cnt2++;
            }

            if(cnt1)last+=cnt1;
            else if(cnt2==-1)last=0;
            else{
                last=max(0LL, last-cnt2);
            }

            ans+=last;
        }

        if(flag){
            cout << ans << endl;
        }else{
            cout << -1  << endl;
        }
    }
    return 0;
}
