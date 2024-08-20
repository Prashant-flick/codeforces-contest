#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int ans[N], vis[N], ptr;
int mp[N];

bool isGood(int num1, int pos){
  if(pos&1) return num1<ans[pos];
  else return num1>ans[pos];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      mp[arr[i]]++;
      vis[arr[i]]=0;
    }

    ptr=0;

    for(int i=0; i<n; i++){
      mp[arr[i]]--;
      if(!ptr)ans[ptr++]=arr[i], vis[arr[i]]=1;
      else{
        if(vis[arr[i]])continue;

        while((ptr && mp[ans[ptr-1]] && isGood(arr[i], ptr-1)) || (ptr>=2 && mp[ans[ptr-1]] && mp[ans[ptr-2]] && isGood(arr[i], ptr-2))){
          if((ptr && mp[ans[ptr-1]] && isGood(arr[i], ptr-1))){
            vis[ans[ptr-1]]=0;
            ptr--;
          }else{
            vis[ans[ptr-1]]=0;
            ptr--;
            vis[ans[ptr-1]]=0;
            ptr--;
          }
        }

        ans[ptr++]=arr[i];
        vis[arr[i]]=1;
      }
    }

    cout << ptr << endl;
    for(int i=0; i<ptr; i++){
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}