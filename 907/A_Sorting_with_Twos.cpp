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
        int arr[n];
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(i!=0 && arr[i]<arr[i-1]){
                if(__builtin_popcount(i)>1){
                    flag=false;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    
    return 0;
}