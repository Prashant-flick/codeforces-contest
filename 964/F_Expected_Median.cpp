#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD=1e9+7;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int fact[200005];
  fact[0]=1;
  fact[1]=1;
  for(int i=2; i<200005; i++){
    fact[i]=(fact[i-1]*i)%MOD;
  }
  
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int arr[n];
    int ones=0;
    for (int i = 0; i < n; i++){
      cin >> arr[i];
      if(arr[i]==1)ones++;
    }
    if(ones<=k/2){
      cout << 0 << endl;
      continue;
    }else{
      int ones=0;
      int zero=0;
      int ans=0;
      int cnt=0;
      for(int i=0; i<n; i++){
        if(arr[i]==1){
          ones++;
        }else{
          zero++;
        }
        if(i>=k-1){
          cnt++;
          if(ones>k/2){
            if(cnt==1){
              if(zero==0){
                ans=1;
              }else{
                int newz=k-ones;
                newz=zero-newz+1;
                ans=((newz*(newz+1))/2)%MOD;
              }
            }else{
              if(arr[i]==0){
                int nzero=ones-(k/2+1);
                nzero+=zero-1;
                // cout << nzero << " " << k/2 << endl;
                // cout << fact[nzero] << " " << fact[k/2] << endl;
                int mzero=k/2;
                if(mzero==0)mzero=1;
                ans=ans+((fact[nzero]/(fact[mzero]*fact[nzero-k/2]))*mzero)%MOD;
                // cout << ans << endl;
              }else{
                int nzero=ones-(k/2+1)-1;
                nzero+=zero;
                // cout << nzero << " " << k/2 << endl;
                // cout << fact[nzero] << " " << fact[k/2] << endl;
                int mzero=k/2;
                if(mzero==0)mzero=1;
                ans=ans+((fact[nzero]/(fact[mzero]*fact[nzero-k/2])*mzero)*(k/2+1))%MOD;
                // cout << ans << endl;
              }
            }
          }
        }
      }
      cout << ans << endl;
    }

    

    
    
  }
  
}