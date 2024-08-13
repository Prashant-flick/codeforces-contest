#include <bits/stdc++.h>
using namespace std;
#define int long long

void maketree(unordered_map<int,vector<int>> &adj, int k, int i, int *p){
  if(k==1)return;

  adj[p[i]].push_back(p[i+1]);
  adj[p[i]].push_back(p[i+k]);
  maketree(adj, k/2, i+1, p);
  maketree(adj, k/2, i+k, p);
  return;
}


void swap2(int x, int y, unordered_map<int, vector<int>> &adj, int *curr, int &diff, int *par){
  for(int &v: adj[y]){
    if(curr[v]==par[v]){
      diff++;
    }
    curr[v]=x;
    if(curr[v]==par[v]){
      diff--;
    }
  }

  for(int &v: adj[x]){
    if(curr[v]==par[v]){
      diff++;
    }
    curr[v]=y;
    if(curr[v]==par[v]){
      diff--;
    }
  } 
  
  if(adj[y].size()==2 && adj[x].size()==2){
    int temp=adj[y][0];
    adj[y][0]=adj[x][0];
    adj[x][0]=temp;
    temp=adj[y][1];
    adj[y][1]=adj[x][1];
    adj[x][1]=temp;
  }else if(adj[y].size()==2){
    adj[x].push_back(adj[y][0]);
    adj[x].push_back(adj[y][1]);
    adj[y].pop_back();
    adj[y].pop_back();
  }else if(adj[x].size()==2){
    adj[y].push_back(adj[x][0]);
    adj[y].push_back(adj[x][1]);
    adj[x].pop_back();
    adj[x].pop_back();
  }
  
  if(curr[x]==0){
    adj[curr[x]][0]=y;
  }else{
    if(adj[curr[x]][0]==x){
      adj[curr[x]][0]=y;
    }else{
      adj[curr[x]][1]=y;
    }
  }

  if(curr[y]==0){
    adj[curr[y]][0]=x;
  }else{
    if(adj[curr[y]][0]==y){
      adj[curr[y]][0]=x;
    }else{
      adj[curr[y]][1]=x;
    }
  }

  int parx=curr[x];
  if(curr[x]==par[x])diff++;
  curr[x]=curr[y];
  if(curr[x]==par[x])diff--;
  if(curr[y]==par[y])diff++;
  curr[y]=parx;
  if(curr[y]==par[y])diff--;

  return;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    int par[n+1];
    par[1]=0;
    for(int i=2; i<=n; i++){
      cin >> par[i];
    }
    int p[n+1];
    for(int i=1; i<=n; i++){
      cin >> p[i];
    }

    unordered_map<int, vector<int>> adj;
    int k = log2(n);
    adj[0].push_back(p[1]);
    maketree(adj, (1<<k), 1, p);
    int curr[n+1];
    for(auto it: adj){
      for(int &v: it.second){
        curr[v]=it.first;
      }
    }

    int diff=0;
    for(int i=1; i<=n; i++){
      if(par[i]!=curr[i])diff++;
    }

    while(q--){
      int x,y;
      cin >> x >> y;
      swap2(p[x], p[y], adj, curr, diff, par);
      swap(p[x], p[y]);
      if(diff==0){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }
  

}