#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int t=1;
  cin >> t;
  while (t--)
  {
    int n,m,k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    int arr[w];
    for (int i = 0; i < w; i++)
    {
      cin>>arr[i];
    }

    int xmin=min(k,m-k+1);
    int ymin=min(k,n-k+1);
    int grid[n][m];
    grid[0][0]=1;
    map<int,int, greater<int>> mp;
    mp[grid[0][0]]++;
    for(int i=1; i<m; i++){
      if(xmin>i){
        grid[0][i]=grid[0][i-1]+1;
      }
      else if((m-xmin)<i){
        grid[0][i]=grid[0][i-1]-1;
      }else{
        grid[0][i]=grid[0][i-1];
      }
      mp[grid[0][i]]++;
    }
    for(int i=1; i<n; i++){
      if(ymin>i){
        grid[i][0]=grid[i-1][0]+1;
      }
      else if((n-ymin)<i){
        grid[i][0]=grid[i-1][0]-1;
      }else{
        grid[i][0]=grid[i-1][0];
      }
      mp[grid[i][0]]++;
    }

    for(int i=1; i<n; i++){
      for(int j=1; j<m; j++){
        grid[i][j]=(grid[i][0]*1LL*grid[0][j]);
        mp[grid[i][j]]++;
      }
    }

    int ans=0;
    sort(arr, arr+w);
    int i=w-1;
    auto it = mp.begin();

    while(it!=mp.end() && i>=0){
      int a = it->first;
      int b = it->second;
      while(i>=0 && b--){
        ans = ans+(a*1LL*arr[i]);
        i--;
      }
      it++;
    }

    cout << ans << endl;
  }
  
}