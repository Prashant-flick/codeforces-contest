#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int b[n];
        int prod=1;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            prod*=b[i];
        }
        // cout << prod << endl;
        if(prod>2023 || 2023%prod!=0 || (k==0 && prod!=2023)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            cout << 2023/prod << " ";
            for (int i = 0; i < k-1; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }

    }
    
    return 0;
}