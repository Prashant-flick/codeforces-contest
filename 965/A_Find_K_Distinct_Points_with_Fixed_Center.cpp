#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int t=1;
  cin >> t;
  while(t--){
    int x,y,n;
    cin >> x >> y >> n;
    vector<int> ans1(n);
    vector<int> ans2(n);
    int a=x*n;
    int b=y*n;
    if(a==0){
      if(n%2!=0){
        ans1[0]=0;
        for(int i=1; i<n; i++){
          ans1[i]=i;
          ans1[i+1]=-i;
          i++;
        }
      }else{
        ans1[0]=1;
        ans1[1]=-1;
        for(int i=2; i<n; i++){
          ans1[i]=i;
          ans1[i+1]=-i;
          i++;
        }
      }
    }else{
      for(int i=0; i<n-1; i++){
        ans1[i]=i;
        a-=i;
      }
      if(a>=0 && a<n-1){
        a+=n-2;
        ans1[n-2]=a+1;
        a-=a+1;
      }
      ans1[n-1]=a;
    }

    if(b==0){
      if(n%2!=0){
        ans2[0]=0;
        for(int i=1; i<n; i++){
          ans2[i]=i;
          ans2[i+1]=-i;
          i++;
        }
      }else{
        ans2[0]=1;
        ans2[1]=-1;
        for(int i=2; i<n; i++){
          ans2[i]=i;
          ans2[i+1]=-i;
          i++;
        }
      }
    }else{
      for(int i=0; i<n-1; i++){
        ans2[i]=i;
        b-=i;
      }
      if(b>=0 && b<n-1){
        b+=n-2;
        ans2[n-2]=b+1;
        b-=b+1;
      }
      ans2[n-1]=b;
    }

    for(int i=0; i<n; i++){
      cout << ans1[i] << " " << ans2[i] << endl;
    }
  }
}