#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        long long num = 0;
        int ans=0;
        // long long dp[]
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(i!=0){
                while(arr[i]<num){
                    ans++;
                    arr[i]*=2;
                }
                num=arr[i];
            }else{
                num=arr[i];
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}