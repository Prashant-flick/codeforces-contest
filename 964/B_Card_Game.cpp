#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if((a1>b1 && a1>b2 && a2>b1 && a2>b2)){
      cout << 4 << endl;
    }else if((a1>b1 && a2>b2) || (a1>b2 && a2>b1)){
      cout << 2 << endl;
    }else{
      cout << 0 << endl;
    }
    
  }
  
}