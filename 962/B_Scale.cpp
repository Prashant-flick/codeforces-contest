#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int x){
    for(int i=2; i<=x/2; i++){
        if(x%i==0)return false;
    }
    return true;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<string> vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }
        int i=0;
        while(i<n){
            int j=0;
            while(j<n){
                cout << vec[i][j];
                j+=k;
            }
            cout << endl;
            i+=k;
        }

    }
    return 0;
}