#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n+1]={0};
        int j=1;
        for(int i=1; i<=n; i++){
            if(i%k==0){
                arr[i]=j;
                j++;
            }
        }
        for(int i=1; i<=n; i++){
            if(arr[i]==0){
                arr[i]=j;
                j++;
            }
        }
        for(int i=1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}