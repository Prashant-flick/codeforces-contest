#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,f,k;
        cin >> n >> f >> k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int fav = arr[f-1];
        sort(arr, arr+n);
        if(n==k){
            cout << "YES" << endl;
            continue;
        }
        if(((n-1)-k>=0 && arr[(n-1)-k]==fav) && (n-k<n && arr[n-k]==fav)){
            cout << "MAYBE" << endl;
        }else if(arr[(n-1)-k]>=fav){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    
    return 0;
}