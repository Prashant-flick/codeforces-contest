#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;

void dfs(unordered_map<int,vector<int>> &adj, int i, int cnt, vector<int> &store){
  if(i>n){
    return;
  }
  if(store[i]!=-1){
    store[i]=min(store[i], cnt);
  }else{  
    store[i]=cnt;
  }
  for(int &v: adj[i]){
    if(store[v]!=-1){
      if(cnt+1<store[v]){
        dfs(adj, v, cnt+1, store);
      }
    }else{
      dfs(adj, v, cnt+1, store);
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    cin >> n >> m;
    unordered_map<int,vector<int>> adj;
    int maxi[n+1]={0};
    int i=1;
    for(; i<=m; i++){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[i].push_back(i+1);
      maxi[a]=max(maxi[a],b);
    }

    for(; i<n; i++){
      adj[i].push_back(i+1);
    }

    // queue<pair<int,int>> q;
    // q.push({1,0});
    // while(!q.empty()){
    //   auto it = q.front();
    //   int u=it.first;
    //   // itn     
    // }

    vector<int> store(n+1,-1);
    store[1]=0;
    for(int i=1; i<n; i++){
      if(store[i]!=-1){
        store[i]=min(store[i-1]+1, store[i]);
      }else{
        store[i]=store[i-1]+1;
      }
      if(maxi[i]!=0){
        dfs(adj, i, store[i], store);
      }
    }

    for(int i=2; i<n; i++){
      if(maxi[i]!=0){
        int prev=maxi[i-1]-store[i-1];
        int curr=maxi[i]-store[i];
        if(curr<prev){
          maxi[i]=maxi[i-1];
          store[i]=store[i-1];
        }
      }else{
        maxi[i]=maxi[i-1];
        store[i]=store[i-1];
      }
    }

    for(int i=1; i<n; i++){
      if(i==1){
        cout << 1;
      }else{
        if(i+store[i-1]+1<maxi[i-1]){
          cout << 0;
        }else{
          cout << 1;
        }
      }
    }
    cout << endl;
  }
  return 0;
}