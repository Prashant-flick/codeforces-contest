#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int f=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]!=0)f=1;
        }
        if(arr[0] && arr[1]){
            int f=0;
            for(int i=2; i<n; i++){
                if(!arr[i])f=1;
            }
            if(f){
                cout << 2 << endl;
                cout << 3 << " " << n << endl;
                cout << 1 << " " << 3 << endl;
            }else{
                cout << 1 << endl;
                cout << 1 << " " << n << endl;
            }
        }else{
            int f=0;
            for(int i=2; i<n; i++){
                if(!arr[i])f=1;
            }
            if(f){
                cout << 3 << endl;
                cout << 3 << " " << n << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
            }else{
                cout << 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << n-1 << endl;
            }
        }
    }
}