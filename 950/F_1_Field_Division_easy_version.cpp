#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int,int>> vec(k);
        map<int,int> mp;
        
        for(int i = 0; i < k; i++){
            int r, c;
            cin >> r >> c;
            vec[i] = {r, c};
            mp[c] = max(mp[c], r);
        }

        int ans = 0;
        int prev = n;
        int i=1;
        auto it = mp.begin();
        while(it!=mp.end()){

            ans+=(it->first-i)*prev;
            if((n-it->second) < prev){
                prev = (n-it->second);
            }else{
                mp[it->first]=-1;
            }
            i = it->first;
            it++;
        }
        ans+=(m+1-i)*prev;
        cout << ans << endl;

        for(int i = 0; i < k; i++){
            int maxi = mp[vec[i].second];

            if(maxi == vec[i].first){
                cout << 1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
