#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,k;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<pair<int,int>> vec;
        int m=n;
        while(m>=k){
            if(m%2==0){
                m/=2;
                vec.push_back({m,0});
            }else{
                m/=2;
                vec.push_back({m,1});
            }
        }

        reverse(vec.begin(), vec.end());
        m = vec.size();
        int ans=0;
        int cnt=0;
        int i=0;
        while(i<m && vec[i].second==0){
            i++;
        }
        for(; i<m; i++){
            if(vec[i].second==1){
                int a=vec[i].first+1;
                ans+=(a*cnt)+ans;
                ans+=a;
                cnt+=cnt+1;
            }else{
                int a=vec[i].first;
                ans+=(a*cnt)+ans;
                cnt+=cnt;
            }
        }
        cout << ans << endl;
    }
}