#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,n;
        cin >> a >> b >> n;
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i]>=a){
                sum+=(a-1);
            }else{
                sum+=arr[i];
            }
        }
        sum++;
        sum+=(b-1);
        cout << sum << endl;
    }
    
    return 0;
}