#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int t;cin>> t;
    while(t--){
        int n,u;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        bool flag=true;
        int cnt=1;
        for(int i=0; i<n-1; i++){
            if(arr[i]==arr[i+1]){
                cnt++;
            }else{
                if(cnt<2){
                    flag=false;
                    break;
                }
                cnt-=2;
                if(arr[i+1]-arr[i]>1){
                    int c = arr[i+1]-(arr[i]+1);
                    cnt-=(2*c);
                    if(cnt<0){
                        if(cnt%2!=0){
                            flag=false;
                            break;
                        }
                        cnt=1;
                    }else{
                        cnt++;
                    }
                }else{
                    cnt++;
                }
            }
        }
        if(cnt%2!=0){
            flag=false;
        }
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}