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

        int store[2][n];
        store[0][1]=1;
        // cout << 0 << " " << 1 << "-->" << store[0][1] << endl;
        int j = 1;
        for (int i = 2; i < n; i++)
        {
            store[0][i]=store[0][i-1] + (abs(arr[j]-arr[j-1])<abs(arr[j]-arr[j+1]) ? abs(arr[j]-arr[j+1]) : 1);
            // cout << 0 << " " << i << "-->" << store[0][i] << endl;
            j++;
        }
        store[1][n-2]=1;
        j=n-2;
        // cout << 1 << " " << 3 << "-->" << store[1][3] << endl;
        for (int i = n-3; i>=0 ; i--)
        {
            store[1][i]=store[1][i+1]+ ((abs(arr[j]-arr[j+1])<abs(arr[j]-arr[j-1])) ? abs(arr[j]-arr[j-1]) : 1);
            j--;
            // cout << 1 << " " << i << "-->" << store[1][i] << endl;
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int c1,c2;
            cin >> c1 >> c2;
            c1--;c2--;
            if(c1<c2){
                if(c1==0){
                    cout << store[c1][c2] << endl;
                    continue;
                }
                cout << abs(store[0][c1]-store[0][c2]) << endl;
            }else{
                if(c1==n-1){
                    cout << store[1][c2] << endl;
                    continue; 
                }
                cout << abs(store[1][c1]-store[1][c2]) << endl;
            }
        }
        
        
    }
    
    return 0;
}