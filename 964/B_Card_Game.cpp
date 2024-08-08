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
    int ans1=0;
    int ans2=0;
    if(a1>b1){
      ans1++;
    }else if(a1<b1){
      ans1--;
    }else{
      ans2++;
    }

    if(a2>b2){
      ans1++;
    }else if(a2<b2){
      ans1--;
    }else{
      ans2++;
    }

    int ans3=0;
    int ans4=0;
    if(a1>b2){
      ans3++;
    }else if(a1<b2){
      ans3--;
    }else{
      ans4++;
    }

    if(a2>b1){
      ans3++;
    }else if(a2<b1){
      ans3--;
    }else{
      ans4++;
    }
    int ans=ans1+ans3;
    if(ans1==1 && ans2==1){
      ans++;
    }
    if(ans3==1 && ans4==1){
      ans++;
    }
    if(ans<0)ans=0;
    cout << ans << endl;
    
  }
  
}