#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll total=0;
        for (int i = 0; i < n; i++)
        {
            ll val;
            cin >> val;
            total+=val;
        }
        ll sq = sqrt(total);
        if(sq*sq*1LL == total){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}