#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        while(true){
            bool flag=false;
            for(int i=0; i<n-1; i++){
                if(arr[i]>arr[i+1]){
                    int temp = (arr[i]-arr[i+1]+1)/2;
                    arr[i]-=temp;
                    arr[i+1]+=temp;
                    flag=true;
                }
            }
            if(!flag)break;
        }
        cout << arr[n-1]-arr[0] << endl;
    }
}