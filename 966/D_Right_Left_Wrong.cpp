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
    for(int i=0; i<n; i++){
      cin >> arr[i];
    }
    string s;
    cin >> s;

    int pre[n];
    pre[0]=arr[0];
    for(int i=1; i<n; i++){
      pre[i]=arr[i]+pre[i-1];
    }

    int ans=0;
    int i=0;
    int j=n-1;
    while(i<j){
      while(s[i]!='L'){
        i++;
      }
      while(s[j]!='R'){
        j--;
      }
      if(i>=j){
        break;
      }
      if(i==0){
        ans+=pre[j];
      }else{
        ans+=pre[j]-pre[i-1];
      }
      i++;
      j--;
    }
    cout << ans << endl;
  }
  
}