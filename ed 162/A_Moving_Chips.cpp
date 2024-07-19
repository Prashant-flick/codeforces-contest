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

        int cnt=0;
        int res=0;
        int i=0;
        for(i=0; i<n; i++){
            if(arr[i]==1){
                break;
            }
        }
        bool flag=true;
        for(i; i<n; i++){
            if(arr[i]==0){
                cnt++;
                flag=false;
            }else{
                if(!flag){
                    res+=cnt;
                    cnt=0;
                }
                flag=true;
            }
        }
        cout << res << endl;
    }
    return 0;
}