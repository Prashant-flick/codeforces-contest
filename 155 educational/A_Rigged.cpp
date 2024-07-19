#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p,q;
        cin >> p >> q;
        bool istrue = true;
        for(int i=1; i<n; i++){
            int a;
            int b;
            cin >> a >> b;
            if(a>=p){
                if(b>=q){
                    istrue = false;
                }
            }
        }
        if(istrue){
            cout << p << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}