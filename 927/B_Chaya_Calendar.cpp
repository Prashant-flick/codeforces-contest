#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int res=arr[0];
        for(int i=1; i<n; i++){
            // cout << res << endl;
            if(arr[i]<=res){
                res = ((res/arr[i])+1)*arr[i];
            }else{
                res = arr[i];
            }
        }

        cout << res << endl;
    }
    return 0;
}