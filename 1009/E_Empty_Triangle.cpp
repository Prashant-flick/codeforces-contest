#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        cin >> n;
        int x=1,y=n/2+1,z=n;
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