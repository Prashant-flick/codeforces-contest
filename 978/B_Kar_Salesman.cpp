#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        int mx=0,sum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mx=max(mx,arr[i]);
			sum+=arr[i];
        }
        cout<< max(mx,sum/x+(sum%x!=0?1:0)) << endl;
    }
    
}