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
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            min1 = min(min1, arr[i]);
        }

        for(int i=0; i<n; i++){
            if(arr[i]%min1!=0){
                min2=min(min2, arr[i]);
            }
        }
        if(min2==INT_MAX){
            cout << "Yes" << endl;
            continue;
        }
        bool flag=true;
        for(int i=0; i<n; i++){
            if(arr[i]%min1!=0 && arr[i]%min2!=0){
                flag=false;
                break;
            }
        }

        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
}
