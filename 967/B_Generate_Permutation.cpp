#include<bits/stdc++.h>
using namespace std;

int main(){
  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n%2==0){
      cout << -1 << endl;
    }else{
      int arr[n];
      arr[n/2]=1;
      int j=3;
      for(int i=0; i<n/2; i++){
        arr[i]=j;
        j+=2;
      }
      j=2;
      for(int i=n-1; i>n/2; i--){
        arr[i]=j;
        j+=2;
      }

      for(int i=0; i<n; i++){
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
}