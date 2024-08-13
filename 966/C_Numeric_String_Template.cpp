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
    int arr[n];
    for(int i=0; i<n; i++)cin >> arr[i];

    int q;
    cin >> q;
    while (q--)
    {
      string s;
      cin >> s;
      if(s.size()!=n){
        cout << "NO" << endl;
      }else{
        unordered_map<char,int> mp;
        unordered_map<int,char> mp1;
        bool flag=true;
        for(int i=0; i<n; i++){
          if(mp.find(s[i])!=mp.end()){
            if(mp[s[i]]!=arr[i]){
              flag=false;
              break;
            }
          }
          if(mp1.find(arr[i])!=mp1.end()){
            if(mp1[arr[i]]!=s[i]){
              flag=false;
              break;
            }
          }
          mp[s[i]]=arr[i];
          mp1[arr[i]]=s[i];
        }
        if(flag){
          cout << "YES" << endl;
        }else{
          cout << "NO" << endl;
        }
      }
    }
    
  }
  
}