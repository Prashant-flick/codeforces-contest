#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> arr(m);
        for(int i=0; i<m; i++)cin >> arr[i];
        sort(begin(arr), end(arr));
        while(q--){
            int d;
            cin >> d;
            int a = lower_bound(arr.begin(), arr.end(), d)-arr.begin();
            if(arr[a]==d){
                cout << 1 << endl;
                continue;
            }
            if(a==0){
                cout << arr[a]-1 << endl;
                continue;
            }
            int b=a-1;
            if(a==m){
                cout << n-arr[b] << endl;
                continue;
            }
            int a1 = arr[a]-d;
            int a2 = d-arr[b];
            cout << (a1+a2)/2 << endl;
        }
    }
    
}