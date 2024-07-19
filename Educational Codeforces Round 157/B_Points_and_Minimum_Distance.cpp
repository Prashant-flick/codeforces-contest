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
        int arr[2*n];
        for (int i = 0; i < 2*n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+2*n);
        int ans=0;
        for (int i = 1; i < n; i++)
        {
            ans+=((arr[i]-arr[i-1]));
        }
        for (int i = n+1; i < 2*n; i++)
        {
            ans+=((arr[i]-arr[i-1]));
        }
        cout << ans << endl;
        int i=0;
        int j=n;
        while(i<n){
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j++;
        }
    }
    
    return 0;
}