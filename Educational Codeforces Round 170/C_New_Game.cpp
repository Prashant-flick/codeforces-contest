#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
        }

        auto it = mp.begin();
        vector<pair<int,int>> vec;
        while(it!=mp.end()){
            int a = it->first;
            int b = it->second;
            vec.push_back({a,b});
            it++;
        }

        int check=1;
        int ans=vec[0].second;
        int prev=vec[0].first;
        int sum=vec[0].second;

        int m = vec.size();
        int i=0,j=1;
        while(j<m){
            if(prev+1==vec[j].first){
                check++;
                if(check>k){
                    sum-=vec[i].second;
                    i++;
                    check--;
                }
                prev=vec[j].first;
                sum+=vec[j].second;
                ans=max(ans,sum);
                j++;
            }else{
                check=1;
                i=j;
                prev=vec[j].first;
                sum=vec[j].second;
                ans=max(ans,sum);
                j++;
            }
        }
        cout << ans << endl;
    }
}