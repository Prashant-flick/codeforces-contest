#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int pre[n]={0};
        if(s[n-1]=='1'){
            pre[n-1]=1;
        }
        for(int i=n-2; i>=0; i--){
            if(s[i]=='1'){
                pre[i]=pre[i+1]+1;
            }else{
                pre[i]=pre[i+1];
            }
        }

        vector<int> cnt(n,0);
        cnt[0]=0;
        for(int i=1; i<n; i++){
            cnt[i]=(pre[i])-((n-i)-pre[i]);
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans=0;
        int res=0;
        for(int i=0; i<n; i++){
            if(cnt[i]<=0){
                break;
            }
            ans+=cnt[i];
            res++;
            if(ans>=k){
                break;
            }
        }
        
        if(ans>=k){
            cout << res+1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}