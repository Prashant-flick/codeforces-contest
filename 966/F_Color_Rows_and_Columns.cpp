#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int t=1;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    int arr[n];
    int brr[n];
    for(int i=0; i<n; i++)cin >> arr[i] >> brr[i];

    vector<vector<int>> cost(n, vector<int> (k+1, 1e9));
    for(int i=0; i<n; i++){
      for(int a=0; a<=arr[i]; a++){
        for(int b=0; b<=brr[i]; b++){
          if(a+b>k)continue;
          cost[i][a+b]=min(cost[i][a+b], a*brr[i] + b*arr[i] - a*b);
        }
      }
    }

    vector<int> dp(k+1, 1e9);
    dp[0]=0;
    for(int i=0; i<n; i++){
      vector<int> dp1(k+1, 1e9);
      for(int j=0; j<=k; j++){
        for(int l=0; l<=k; l++){
          if(j+l>k)continue;
          dp1[j+l]=min(dp1[j+l], dp[j]+cost[i][l]);
        }
      }
      dp=dp1;
    }
    if(dp[k]==1e9){
      cout << -1 << endl;
      continue;
    }
    cout << dp[k] << endl;
  }
  
}