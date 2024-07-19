#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int totsum1=0;
        int arr1[n];
        int arr2[m];
        int min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
            totsum1+=arr1[i];
            if(min1>arr1[i]){
                min1=arr1[i];
            }
            if(max1<arr1[i]){
                max1=arr1[i];
            }
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
            if(min2>arr2[i]){
                min2=arr2[i];
            }
            if(max2<arr2[i]){
                max2=arr2[i];
            }
        }

        if(k%2==0){
            if(max1<=min2){
                cout << totsum1 << endl;
            }else{
                if(min1>=max2){
                    int rem = max1-min2;
                    cout << totsum1-rem << endl;
                }else{
                    int rem1 = max2-min1;
                    totsum1+=rem1;
                    int rem2 = (max(max1,max2)-min(min1, min2));
                    totsum1-=rem2;
                    cout << totsum1 << endl;
                }
            }
        }else{
            if(k%2!=0){
                if(max1<=min2){
                    int rem = max2-min1;
                    cout << totsum1+rem << endl;
                }else{
                    if(min1>=max2){
                        cout << totsum1 << endl;
                    }else{
                        int rem1 = max2-min1;
                        totsum1+=rem1;
                        cout << totsum1 << endl;
                    }
                }
            }
        }
    }
    return 0;
}