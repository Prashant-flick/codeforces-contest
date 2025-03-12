#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,x=1,y=2,z=3;
        cin >> n;
        cout << "? " << x << " " << y << " " << z << endl;
        cout.flush();
        cin >> a;
        while(a!=0){
            x=y,y=z,z=a;
            cout << "? " << x << " " << y << " " << z << endl;
            cout.flush();
            cin >> a;
        }
        cout << "! " << x << " " << " " << y << " " << z << endl;
    }
}