#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        if(n>=m){
            cout << n << endl;
        }else{
            cout << n+(m-n)+(m-n>k?(m-n)-k:0) << endl;
        }
    }
    
    return 0;
}