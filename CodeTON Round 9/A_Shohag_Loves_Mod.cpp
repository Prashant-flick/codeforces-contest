#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cout << (i*2)-1 << " ";
        }
        cout << endl;
    }

    return 0;
}