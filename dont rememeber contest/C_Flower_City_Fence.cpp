#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int maxi = n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if(n==1){
            if(arr[0]==1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            bool istrue = true;
            for (int i = 0; i < n; i++)
            {
                if(arr[0]>n){
                    istrue = false;
                    break;
                }else if(arr[arr[i]-1]<i+1){
                    istrue = false;
                    break;
                }
            }
            if(istrue){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            } 
        }
    }
    
    return 0;
}