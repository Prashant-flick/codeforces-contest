#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        bool flag = true;
        for(int i=1; i<n; i++){
            if(arr[i]>=arr[i-1]){
                arr[i]-=arr[i-1];
                arr[i-1]=0;
            }else{
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}