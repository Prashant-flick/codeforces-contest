#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        int arr[n];
        int sum=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i]/2;
            cnt+=arr[i]%2==0?0:1;
        }
        cout << (sum*2)+(cnt<=(r-sum)?cnt:(r-sum)*2 - cnt)<< endl;
    }
    
}