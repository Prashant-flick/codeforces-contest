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
    for(int i=0; i<n; i++)cin >> arr[i];
    int remsize=n%k;
    if(remsize==0){
      remsize=k;
    }

    int mid = 0;
    if(k*2>n){
      mid=k*2-n;
    }
    int i1=n-mid;
    i1/=2;
    // cout << mid << " " << i1 << " " << remsize << endl;
    int j=0;
    int i=0;
    map<int,int> mp;
    int ans=0;
    if(mid==0 || n<=k){
      while(j<=n){
        if(j-i<remsize){
          mp[arr[j]]++;
          j++;
        }else if(j-i==remsize){
          auto it = mp.begin();
          ans = max(ans, it->first);
          if(j==n)break;
          mp[arr[i]]--;
          if(mp[arr[i]]==0){
            mp.erase(arr[i]);
          }
          i++;
          mp[arr[j]]++;
          j++;
        }
      }
    }else{
      while(j<=i1){
        if(j-i<remsize){
          mp[arr[j]]++;
          j++;
        }else if(j-i==remsize){
          auto it = mp.begin();
          ans = max(ans, it->first);
          if(j==n)break;
          mp[arr[i]]--;
          if(mp[arr[i]]==0){
            mp.erase(arr[i]);
          }
          i++;
          mp[arr[j]]++;
          j++;
        }
      }
      mp.clear();
      j=mid+i1;
      i=mid+i1;
      while(j<=n){
        if(j-i<remsize){
          mp[arr[j]]++;
          j++;
        }else if(j-i==remsize){
          auto it = mp.begin();
          ans = max(ans, it->first);
          if(j==n)break;
          mp[arr[i]]--;
          if(mp[arr[i]]==0){
            mp.erase(arr[i]);
          }
          i++;
          mp[arr[j]]++;
          j++;
        }
      }
    }
    
    cout << ans << endl;
  }
  
}