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
        
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> b(n);
        int i=0;
        int j=1;
        while(i<n){
            if(arr[i]!=j){
                b[i]=j;
                j++;
                i++;
            }else if(arr[i]==j){
                b[i]=j+1;
                j+=2;
                i++;
            }
        }
        cout << b[n-1] << endl;
        
        
    }
    
    return 0;
}