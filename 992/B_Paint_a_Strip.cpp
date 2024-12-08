#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum=1;
        int cnt=1;
        while(sum<n){
            sum++;
            sum=sum*2LL;
            cnt++;
        }
        cout << cnt << endl;
    }
}