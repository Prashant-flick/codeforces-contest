#include<bits/stdc++.h>
using namespace std;

// #define int long long

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        if(n==1){
          if(s[0]!='z'){
            s+=s[0]+1;
          }else{
            s+=s[0]-1;
          }
          cout << s << endl;
          continue;
        }
        string ans="";
        ans+=s[0];
        int i=1;
        bool flag=false;
        while(i<n){
          while(s[i]==s[i-1]){
            if(s[i]!='z'){
              ans+=s[i]+1;
            }else{
              ans+=s[i]-1;
            }
            flag=true;
            break;
            i++;
          }
          if(flag){
            break;
          }
          ans+=s[i];
          i++;
        }
        while(i<n){
          ans+=s[i];
          i++;
        }
        if(!flag){
          if(s[i-1]!='z'){
              ans+=s[i-1]+1;
            }else{
              ans+=s[i-1]-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}