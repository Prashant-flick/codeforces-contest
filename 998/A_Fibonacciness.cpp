#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int a1,a2,a3,a4,a5;
        cin >> a1 >> a2 >> a4 >> a5;
        if((a1+a2+a2)==a4){
            if(a1+a2+a4==a5){
                cout << 3 << endl;
            }else{
                cout << 2 << endl;
            }
        }else if(a4-a2+a4==a5){
            if(a1+a2==a4-a2){
                cout << 3 << endl;
            }else{
                cout << 2 << endl;
            }
        }else if(a1+a2+a4==a5){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
    }
}