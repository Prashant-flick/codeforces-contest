#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[1005][1005],f[1005][5005],cnt[1005],p[1005];
priority_queue<pair<int,int> >q;
int main(){
  cnt[0]=1,cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++){
      while(!q.empty())q.pop();
      p[n+1]=cnt[n+1]=1,q.push(make_pair(a[1][i],n+1));
      for(int j=0;j<i;j++)p[j]=1,q.push(make_pair(f[j][1]+a[j+2][i],j));
      while(cnt[i]<k&&!q.empty()){
        int u=q.top().second,v=q.top().first;
        f[i][++cnt[i]]=v,q.pop();
        if(p[u]<cnt[u])q.push(make_pair(f[u][++p[u]]+a[u+2][i],u));
      }
    }
    for(int i=1;i<=k;i++)cout<<f[n][i]<<(i==k?'\n':' ');
    for(int i=1;i<=n+1;i++)cnt[i]=0;
  }
  return 0;
}