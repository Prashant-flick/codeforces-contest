#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+10;
int arr[N];
int cnt[N];

int dfs(string &s, int i, int *vis){
    vis[i]=1;
    if(s[i-1]=='0'){
        if(!vis[arr[i]]){
            return 1+dfs(s, arr[i], vis);
        }else{
            return 1;
        }
    }else{
        if(!vis[arr[i]]){
            return dfs(s, arr[i], vis);
        }else{
            return 0;
        }
    }
}

void dfs2(int i, int *vis, int sum){
    vis[i]=2;
    if(vis[arr[i]]!=2){
        cnt[arr[i]]=sum;
        dfs2(arr[i], vis, sum);
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)cin >> arr[i];
        string s;
        cin >> s;
        int vis[n+1]={0};
        memset(cnt, 0, sizeof cnt);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                cnt[i]=dfs(s, i, vis);
                dfs2(i, vis, cnt[i]);
            }
        }
        for(int i=1; i<=n; i++){
            cout << cnt[i] << " ";
        }
        cout << endl;
    }
}