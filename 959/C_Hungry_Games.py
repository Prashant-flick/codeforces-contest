#include <bits/stdc++.h>
using namespace std;
#define int long long





void solve() {
   int n,x;
   cin>>n>>x;
   int a[n],pre[n+1]={0},dp[n+3]={0};
   for(int i=0;i<n;++i){
    cin>>a[i];
    pre[i+1]=pre[i]+a[i];
   }
   int ans=0;
   for(int i=n-1;i>=0;--i){
    int val=pre[i]+x;
   
    auto index=lower_bound(pre,pre+n+1,val)-pre;
      if(index==n+1)dp[i]+=(n-i);
       else if(val==pre[index])dp[i]+=(index-i)+dp[index+1];
        else dp[i]+=(index-i-1)+dp[index];
   }
   for(int i=0;i<n+3;++i){
    ans+=dp[i];
   }
   cout<<ans<<endl;
  
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}