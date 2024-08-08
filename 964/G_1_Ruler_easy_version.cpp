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
    int mid=(l+r)/2;
    while(l<r){
      cout << "? " << mid  << " " << mid << endl << endl;
      cin >> s;
      if(s==(mid*mid)){
        l=mid+1;
      }else{
        r=mid;
      }
      mid=(l+r)/2;
      
    }
    cout << "! "<< mid << endl;
    cout.flush();
  }
  
}