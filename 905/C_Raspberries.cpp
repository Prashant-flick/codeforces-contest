#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int arr[n];
        bool flag=false;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i]%k==0){
                flag=true;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        if(k==2){
            cout << 1 << endl;
        }
        else if(k==3){
            int maxi=1;
            for (int i = 0; i < n; i++)
            {
                if(arr[i]%k==2){
                    maxi=2;
                    break;
                }
            }
            if(maxi==1){
                cout << 2 << endl;
            }else{
                cout << 1 << endl;
            }
        }else if(k==5){
            int maxi=1;
            for (int i = 0; i < n; i++){
                maxi = max(maxi, arr[i]%k);
                if(maxi==4)break;
            }
            cout << k-maxi << endl;
        }else{
            int cnt=0;
            int maxi=1;
            for (int i = 0; i < n; i++)
            {
                maxi = max(maxi, arr[i]%4);
                if(arr[i]%2==0){
                    cnt++;
                }
                if(cnt==2)break;
            }
            if(cnt==2){
                cout << 0 << endl;
            }else if(cnt==1 || maxi==3){
                cout << 1 << endl;
            }else{
                cout << 2 << endl;
            }
        }
        
    }
    
    return 0;
}