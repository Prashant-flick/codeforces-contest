#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int t;cin>> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int ans = y-1;
        while(ans<x){
            ans+=9;
        }
        if(ans==x){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}