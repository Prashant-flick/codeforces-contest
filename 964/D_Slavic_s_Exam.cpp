#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    string s,t;
    cin >> s >> t;
    int n=s.size();
    int m=t.size();
    int i=0;
    int j=0;
    while(i<n && j<m){
      if(s[i]==t[j] || s[i]=='?'){
        if(s[i]=='?'){
          s[i]=t[j];
        }
        i++;
        j++;
      }else{
        i++;
      }
    }
    if(j==m){
      while(i<n){
        if(s[i]=='?'){
          s[i]='a';
        }
        i++;
      }
      cout << "YES" << endl;
      for(int i=0; i<n; i++){
        cout << s[i];
      }
      cout << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}