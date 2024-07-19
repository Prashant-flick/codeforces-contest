#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int maxi = n/m + (n%m ? 1 : 0);

        if(k>=(n-maxi)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    

    return 0;
}