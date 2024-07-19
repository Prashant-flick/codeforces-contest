#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int arr[n];
        int sumtotal = 0;
        int left[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]==1){
                sumtotal+=1;
                left[i]=sumtotal;
            }else{
                sumtotal-=arr[i]-1;
                left[i]=sumtotal;
            }
        }

        int right[n];
        int sum=0;
        for(int i=n-1; i>=0 ; i--){
            if(arr[i]==1){
                sum+=1;
                right[i]=sum;
            }else{
                sum-=arr[i]-1;
                right[i]=sum;
            }
        }
        

        for(int i=0; i<q; i++){
            int l,r;
            cin >> l >> r;
            if(l==r){
                cout << "NO" << endl;
            }else if(l==1 && r==n){
                if(sumtotal>0){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
            }else if(l==1){
                int s = sumtotal-right[r];
                if(s>0){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
                
            }else if(r==n){
                int s = sumtotal-left[l-2];
                if(s>0){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
            }else{
                int s = sumtotal-(left[l-2]+right[r]);
                if(s>0){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}