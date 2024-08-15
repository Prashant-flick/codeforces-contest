#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    int ans=0;
    int cnt=0;
    for(int i=0; i<n; i++){
      cin >> arr[i];
      if(arr[i]<=2){
        if(arr[i]==1){
          ans+=1;
        }
      }else{
        if(arr[i]!=4){
          cnt++;
        }
      }
    }
    
    if(ans%2==1){
      if(cnt%2==1){
        cout << "Alice" << endl;
      }else{
        cout << "Bob" << endl;
      }
    }else{
      if(cnt%2==0){
        cout << "Bob" << endl;
      }else{
        cout << "Alice" << endl;
      }
    }
    

    
  }
  
}