#include<bits/stdc++.h>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t=1;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int arr[n];

    int l=INT_MAX;
    int r=INT_MIN;

    for(int i=0; i<n; i++){
      cin >> arr[i];
      l=min(l, arr[i]);
      r=max(r, arr[i]);
    }

    if(k==1){
      cout << r << endl;
      continue;
    }
    int mid=(l+r)/2;
    int ans=0;

    while(l<=r){
      mid=(l+r)/2;
      int dp[n+1]={0};
      dp[0]=0;
      for(int i=1; i<=n; i++){
        int cnt=(arr[i-1]>=mid?1:-1);
        if(i<=k){
          dp[i]=dp[i-1]+cnt;
        }
        else if(i%k==1){
          dp[i]=max(dp[i-k], cnt);
        }else{
          dp[i]=max(dp[i-k], dp[i-1]+cnt);
        }
      }
      if(dp[n]>0){
        ans=mid;
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
    
    cout << ans << endl;
  }
  
}