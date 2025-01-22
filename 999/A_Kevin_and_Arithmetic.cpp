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
        int o=0,e=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]%2==0){
                e++;
            }else{
                o++;
            }
        }
        if(e>0){
            cout << o+1 << endl;
        }else{
            cout << o-(o==0?0:1) << endl;
        }
    }
}