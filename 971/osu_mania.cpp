#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            for(int j=0; j<4; j++){
                if(s[j]=='#'){
                    arr[i]=j+1;
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}