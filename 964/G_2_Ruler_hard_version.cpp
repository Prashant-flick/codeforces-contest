#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t,s;
  cin >> t;
  while (t--)
  {
    int l=1;
    int r=1000;
    int mid1=(2*l+r)/3;
    int mid2=(l+r*2)/3;
    while(l<r){
      cout << "? " << mid1  << " " << mid2 << endl << endl;
      cin >> s;
      if(mid1*mid2==s){
        l=mid2+1;
      }else if((mid1*(mid2+1))==s){
        l=mid1+1;
        r=mid2;
      }else{
        r=mid1;
      }
      mid1=(2*l+r)/3;
      mid2=(l+2*r)/3;
    }
    cout << "! "<< mid2 << endl;
    cout.flush();
  }
  
}