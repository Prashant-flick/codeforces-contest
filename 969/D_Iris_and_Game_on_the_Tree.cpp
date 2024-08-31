#include<bits/stdc++.h>
using namespace std;

#define int long long
int cnt1,cnt0,cnt,cnt2;

void dfs(vector<vector<int>> &mp, int i, int *vis, string &s){
    vis[i]=1;
    if(mp[i].size()==1 && vis[mp[i][0]]==1){
        if(s[i-1]=='1'){
            cnt1++;
        }else if(s[i-1]=='0'){
            cnt0++;
        }else{
            cnt++;
        }
        return;
    }else if(i!=1){
        if(s[i-1]=='?'){
            cnt2++;
        }
    }
    for(int &v: mp[i]){
        if(!vis[v]){
            dfs(mp, v, vis, s);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> mp(n+1);
        for(int i=0; i<n-1; i++){
            int a,b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        string s;
        cin >> s;
        int vis[n+1]={0};
        cnt1=0;
        cnt0=0;
        cnt=0;
        cnt2=0;
        dfs(mp, 1, vis, s);
        int ans=0;
        if(s[0]=='1'){
            ans+=cnt0;
            ans+=(cnt+1)/2;
        }else if(s[0]=='0'){
            ans+=cnt1;
            ans+=(cnt+1)/2;
        }else{
            int ans1=0;
            int ans2=0;
            if(cnt0>0){
                ans1+=cnt0;
                ans1+=cnt/2;
            }else{
                if(cnt2%2==1){
                    ans1+=(cnt+1)/2;
                }else{
                    ans1+=cnt/2;
                }
            }
            if(cnt1>0){
                ans2+=cnt1;
                ans2+=cnt/2;
            }else{
                if(cnt2%2==1){
                    ans2+=(cnt+1)/2;
                }else{
                    ans2+=cnt/2;
                }
            }
            int ans3=0;
            if(cnt0==cnt1){
                ans3+=cnt0;
                if(cnt2%2==1){
                    ans3+=(cnt+1)/2;
                }else{
                    ans3+=cnt/2;
                }
            }
            ans=max(ans3, max(ans1, ans2));
        }
        cout << ans << endl;
    }
}