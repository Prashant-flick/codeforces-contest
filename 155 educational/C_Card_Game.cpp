#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

// int solve(int *arr, int n, int i, bool flag){
//     if(i>=n){
//         return 0;
//     }
//     int istrue = 0;
//     int isfalse = 0;
//     if(flag){
//         istrue = solve(arr,n,i+1,true)+arr[i];
//         isfalse = solve(arr,n,i+1,false);
//     }else{
//         isfalse = solve(arr,n,i+1,false);
//         istrue = solve(arr,n,i+1,true);
//     }
//     return max(istrue, isfalse);
// }

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n+1];
        for (int i = 1; i <=n; i++)
        {
            cin >> arr[i];
        }
        if(n==1){
            if(arr[1]>0){
                cout << arr[1] << endl;
            }else{
                cout << 0 << endl;
            }
        }
        else if(arr[1]>=0 || (arr[1]<0 && arr[2]<=0)){
            int sum=0;
            for (int i = 1; i <=n; i++)
            {
                if(arr[i]>0){
                    sum+=arr[i];
                }
            }
            cout << sum << endl;
        }else if(arr[2]>=0){
            int sum = 0;
            if(arr[2]+arr[1]>0){
                sum+=arr[2]+arr[1];
            }
            for (int i = 3; i <=n ; i++)
            {
                if(arr[i]>0){
                    sum+=arr[i];
                }
            }
            cout << sum << endl;
            
        }
    }
    
    return 0;
}