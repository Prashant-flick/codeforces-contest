#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t=1;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n];
        int brr[n];
        pair<int,int> mp[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<n; i++){
            cin >> brr[i];
            mp[i] = make_pair(arr[i], brr[i]);
        }

        int ans=0;
        sort(mp, mp+n);
        for(int i=0; i<n; i++){
            int cur = m;
            int a = min(cur/mp[i].first, mp[i].second);
            cur -= a*mp[i].first;
            
            ans = max(ans, m-cur);
            if(i==n-1 || (mp[i].first + 1LL != mp[i+1].first))continue;

            // cout << mp[i].first << " " << mp[i+1].first << endl;
            // cout << cur << endl;

            int b = min(cur/mp[i+1].first, mp[i+1].second);
            cur -= b*mp[i+1].first;
            b=mp[i+1].second-b;
            // cout << cur << endl;

            if(b>0 && cur>0){
                if(cur>=b){
                    cur-=min(b,a);
                }else if(cur<b){
                    cur-=min(cur,a);
                }
            }

            ans = max(ans, m-cur);
        }

        cout << ans << endl;
    }
}