#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        int arr[n+1];
        arr[0]=0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int tottime=0;
        for (int i = 1; i <= n; i++)
        {
            if(((arr[i]-arr[i-1])*b)<c){
                tottime+=(arr[i]-arr[i-1])*b;
            }else{
                tottime+=c;
            }
        }
        if(tottime<a){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    
    return 0;
}