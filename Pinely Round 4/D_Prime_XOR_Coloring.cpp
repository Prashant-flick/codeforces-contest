#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;

        if(n==1){
          cout << 1 << endl << 1 << endl;
          continue;
        }
        if(n==2){
          cout << 2 << endl;
          cout << 1 << " " << 2 << endl;
          continue;
        }
        if(n==3){
          cout << 2 << endl;
          cout << 1 << " " << 2 << " " << 2 << endl;
          continue;
        }
        if(n==4){
          cout << 3 << endl;
          cout << 1 << " " << 2 << " " << 2 << " " << 3 << endl;
          continue;
        }
        if(n==5){
          cout << 3 << endl;
          cout << 1 << " " << 2 << " " << 2 << " " << 3 << " " << 3 << endl;
          continue;
        }
  
        int i=1;
        cout << 4 << endl;
        while(i<=n){
          cout << 1 << " ";
          i++;
          if(i>n)break;
          cout << 2 << " ";
          i++;
          if(i>n)break;
          cout << 3 << " ";
          i++;
          if(i>n)break;
          cout << 4 << " ";
          i++;
        }
        cout << endl;
    }
    return 0;
}