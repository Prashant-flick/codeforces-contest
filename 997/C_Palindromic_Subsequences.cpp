#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr = {1,1,2,3,1,2};
        for(int i=0; i<2; i++){
            cout << 1 << " ";
        }
        for(int i=0; i<n-3; i++){
            cout << i+2 << " ";
        }
        cout << 1 << endl;
    }
}