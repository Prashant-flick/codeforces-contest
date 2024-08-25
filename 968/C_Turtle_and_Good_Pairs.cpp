#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    for(int i=0; i<n; i++){
      cnt[s[i]-'a']++;
    }
    vector<pair<int,int>> mp;
    for(int i=0; i<26; i++){
      if(cnt[i]>0){
        mp.push_back({cnt[i], i});
      }
    }

    sort(mp.rbegin(), mp.rend());

    auto it=mp.begin();
    int i=1;
    int c=0;
    while(it!=mp.end()){
      int a = it->first;
      int b = it->second;
      while(a--){
        if(i>=n && c==0){
          i=0;
          c=1;
        }
        s[i]=(char)('a'+b);
        i+=2;
      }
      it++;
    }

    cout << s << endl;
  }
}