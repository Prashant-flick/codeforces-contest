#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int t=1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if(n>101 && n<=109){
      cout << "YES" << endl;
    }else if(n>=1010 && n<=1099){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
   
  }
  
}