#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a >> b;
        if((0LL+a+b)%2==0){
            cout << "Bob" << endl;
        }else{
            cout << "Alice" << endl;
        }
    }
    
    return 0;
}