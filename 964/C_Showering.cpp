#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n, s, m;
    cin >> n >> s >> m;
    bool flag=false;
    int r=0;
    for(int i=0; i<n; i++){
      int l1,r1;
      cin >> l1 >> r1;
      if(flag){
        continue;
      }
      if(l1-r>=s){
        flag=true;
        continue;
      }
      if(i==n-1 && m-r1>=s){
        flag=true;
        continue;
      }
      r=r1;
    }
    if(flag){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}