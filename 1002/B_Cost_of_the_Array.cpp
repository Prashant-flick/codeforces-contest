#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k; 
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int maxi = n-k+1;
        if(n==k){
            int i=1;
            for(int j=1; j<n; j+=2){
                if(arr[j]!=i){
                    break;
                }
                i++;
            }
            cout << i << endl;
        }else{
            bool flag=false;
            for(int i=1; i<=maxi && i<n; i++){
                if(arr[i]!=1LL){
                    flag=true;
                    break;
                }
            }
            if(flag){
                cout << 1 << endl;
            }else{
                cout << 2 << endl;
            }
        }
    }
    
}