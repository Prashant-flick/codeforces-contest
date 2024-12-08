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
        int sum=0;
        int odd=0;
        int even=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
            if(i%2==0){
                odd+=arr[i];
            }else{
                even+=arr[i];
            }
        }
        if(sum%n!=0){
            cout << "NO" << endl;
        }else{
            int oddsize = (n+1)/2;
            int evensize = n/2;
            if(odd%oddsize==0 && even%evensize==0 && odd/oddsize==even/evensize){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}