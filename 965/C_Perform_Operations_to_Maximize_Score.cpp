#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;

int med(vector<pair<int,int>> &vec){
  int l=1;
  int r=2e9;
  int mid;
  int ans=0;
  while(l<=r){
    mid=(l+r)/2;
    int cnt=0;
    int k1=k;
    for(int i=n-2; i>=0; i--){
      if(vec[i].first>=mid){
        cnt++;
      }else{
        if(vec[i].second==1){
          if(k1>=(mid-vec[i].first)){
            k1-=(mid-vec[i].first);
            cnt++;
          }else{
            break;
          }
        }
      }
    }
    if(cnt>(n-1)/2){
      ans=mid;
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  return ans;
}

int med1(vector<pair<int,int>> &vec){
  int l=1;
  int r=2e9;
  int mid;
  int ans=0;
  while(l<=r){
    mid=(l+r)/2;
    int cnt=0;
    int k1=k;
    for(int i=n-1; i>=0; i--){
      if(i==((n+1)/2)-1){
        continue;
      }
      if(vec[i].first>=mid){
        cnt++;
      }else{
        if(vec[i].second==1){
          if(k1>=(mid-vec[i].first)){
            k1-=(mid-vec[i].first);
            cnt++;
          }else{
            break;
          }
        }
      }
    }
    if(cnt>(n-1)/2){
      ans=mid;
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  return ans;
}

signed main(){
  int t=1;
  cin >> t;
  while(t--){
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)cin >> arr[i];
    vector<pair<int,int>> vec(n);
    for(int i=0; i<n; i++){
      int temp;
      cin >> temp;
      vec[i]=make_pair(arr[i], temp);
    }
    sort(begin(vec), end(vec));

    int lmid = med(vec);
    int rmid = med1(vec);

    int ans=0;
    for(int i=0; i<n; i++){
      if(vec[i].second){
        int mid=n/2-1;
        if(i <= mid){
          mid++;
        }
        ans=max(ans, vec[i].first+k+vec[mid].first);
      }else{
        if(vec[i].first<rmid){
          ans=max(ans, rmid+vec[i].first);
        }else{
          ans=max(ans, lmid+vec[i].first);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}