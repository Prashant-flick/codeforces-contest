#include <bits/stdc++.h>
using namespace std;

// #define int long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int t = 31 - (__builtin_clz(n));
        cout << (1<<t) << endl;

    }
}
