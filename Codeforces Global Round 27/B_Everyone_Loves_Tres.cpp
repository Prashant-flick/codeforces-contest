#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1 || n==3){
            cout << -1 << endl;
        }else if(n==2){
            cout << "66" << endl;
        }else if(n%2==0){
            string s="";
            for(int i=0; i<n-2; i+=2){
                s+="33";
            }
            s+="66";
            cout << s << endl;
        }else{
            string s="36366";
            for(int i=0; i<n-5; i+=2){
                s="33"+s;
            }
            cout << s << endl;
        }
    }
}