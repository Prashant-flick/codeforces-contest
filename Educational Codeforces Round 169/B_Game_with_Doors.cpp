#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int l,r,L,R;
    cin >> l >> r;
    cin >> L >> R;
    if(r<L || R<l){
      cout << 1 << endl;
    }else{
      int l1=max(l,L);
      int r1=min(r,R);
      int cnt=r1-l1;
      if(l!=L)cnt++;
      if(r!=R)cnt++;
      cout << cnt <<endl;
    }
  }
  
}