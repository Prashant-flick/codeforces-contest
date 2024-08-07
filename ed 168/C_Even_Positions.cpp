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
      string s;
      cin >> s;
      stack<pair<char,int>> st;
      st.push({'(', 0});
      int ans = 0;
      for(int i=1; i<n; i++){
        if(!st.empty()){
          auto it = st.top();
          char ch = it.first;
          int index = it.second;
          if(ch=='(' && (s[i]==')' || s[i]=='_')){
            ans+=(i-index);
            st.pop();
          }else{
            st.push({'(', i});
          }
        }else{
          st.push({'(',i});
        }
      }
      cout << ans << endl;
    }
    return 0;
}