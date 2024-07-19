#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int cnt=0;
        for(int i=1; i<n; i++){
            if(arr[i]<arr[i-1])cnt++;
        }
        if(arr[n-1]>arr[0])cnt++;

        if(cnt>=2){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    
}
