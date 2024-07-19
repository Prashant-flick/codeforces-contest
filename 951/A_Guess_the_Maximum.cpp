#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }


        int mini = INT_MAX;
        for(int i=0; i<n-1; i++){
            mini=min(mini, max(arr[i],arr[i+1]));
        }
        cout << mini-1 << endl;
        
    }
}