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
        cin >> arr[0];
        bool flag = true;
        for(int i=1; i<n; i++){
            cin >> arr[i];
            if(arr[0]!=arr[i]){
                flag = false;
            }
        }
        if(flag){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        cout << "R" << "B" ; 
        for(int i=2; i<n; i++){
            cout << "R";
        }
        cout << endl;
    }
    
}