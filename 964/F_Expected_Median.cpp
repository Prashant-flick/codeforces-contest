#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD=1e9+7;

int fact[200005];
int inv[200005];

int pw(int a, int b){
  int res=1;
  while (b)
  {
    if(b&1) res=(1LL * res * a) %MOD;
    a = (1LL * a * a)%MOD;
    b>>=1;
  }
  return res;
}

int C(int n, int k){
  if(k>n) return 0;
  return (((1LL * fact[n] * inv[k]) % MOD) * inv[n-k])%MOD;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  fact[0]=inv[0]=1;
  for(int i=1; i<200005; i++){
    fact[i]=(fact[i-1]*1LL*i)%MOD;
    inv[i]=pw(fact[i], MOD-2);
  }
  
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int arr[n];
    int ones=0;
    int zeros=0;
    for (int i = 0; i < n; i++){
      cin >> arr[i];
      if(arr[i]==1)ones++;
    }
    zeros=n-ones;
    if(ones<=k/2){
      cout << 0 << endl;
      continue;
    }else{
      int ans=0;
      for(int i=(k+1)/2; i<=k; i++){
        int res1=C(zeros, k-i);
        int res2=C(ones, i);
        int res = 1LL * (res1 *1LL* res2)%MOD;
        ans = (ans+res)%MOD;
      }
      cout << ans << endl;
    }
  }
}