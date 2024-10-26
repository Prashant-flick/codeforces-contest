#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

int modExpo(int base, int exp) {
    int result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

signed main(){
    int t=1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n;i++){
            int temp;
            cin >> temp;
        }

        for(int i=0; i<n; i++){
            cin >> arr[i];
            int ans = modExpo(2, arr[i]);
            cout << ans << endl;
        }
    }
}