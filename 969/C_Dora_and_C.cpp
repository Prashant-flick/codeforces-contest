#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){
    if(b==0 || a==0)return a;
    if(a>b)swap(a,b);
    return gcd(a, b%a);
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        int temp = gcd(a,b);
        for(int i=0; i<n; i++){
            arr[i] = (arr[i]%temp);
        }

        sort(arr, arr+n);

        int ans = arr[n-1]-arr[0];
        for(int i=0; i<n-1; i++){
            int cnt = arr[i] + temp-arr[i+1];
            if(cnt<ans){
                ans=cnt;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
