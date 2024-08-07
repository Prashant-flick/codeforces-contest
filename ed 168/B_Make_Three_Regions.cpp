#include<bits/stdc++.h>
using namespace std;

// #define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
      int n;
      cin >> n;
      string s[2];
      cin >> s[0] >> s[1];

      int ans=0;
      int i=0;
      while(s[0][i]=='x' && s[1][i]=='x'){
        i++;
      }
      int j=n-1;
      while(s[0][j]=='x' && s[1][j]=='x'){
        j--;
      }
      j++;
      for(; i<j-2; i++){
        if(i==0 && i==j-3){
          if((s[0][i]=='x' && s[0][i+2]=='x' && s[1][i]!='x' && s[0][i+1]!='x' && s[1][i+2]!='x')){
            ans++;
          }else if((s[1][i]=='x' && s[1][i+2]=='x' && s[0][i]!='x' && s[1][i+1]!='x' && s[0][i+2]!='x')){
            ans++;
          }
        }
        else if(i==0){
          if((s[0][i]=='x' && s[0][i+2]=='x' && s[1][i]!='x' && s[0][i+1]!='x')){
            ans++;
          }else if((s[1][i]=='x' && s[1][i+2]=='x' && s[0][i]!='x' && s[1][i+1]!='x')){
            ans++;
          }
          
          
        }else if(i==j-3){
          if((s[0][i]=='x' && s[0][i+2]=='x' && s[1][i+2]!='x' && s[0][i+1]!='x')){
            ans++;
          }else if((s[1][i]=='x' && s[1][i+2]=='x' && s[0][i+2]!='x' && s[1][i+1]!='x')){
            ans++;
          }
        }
        else if((s[0][i]=='x' && s[0][i+2]=='x' && s[0][i+1]!='x')){
          ans++;
        }else if((s[1][i]=='x' && s[1][i+2]=='x' && s[1][i+1]!='x')){
          ans++;
        }
      }
      cout << ans << endl;
    }
    return 0;
}