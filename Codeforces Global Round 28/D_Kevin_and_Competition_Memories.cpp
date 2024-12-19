#include<bits/stdc++.h>
using namespace std;

#define int long long
const int size = 3e5+10;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n],brr[m],cnt[m];
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<m; i++)cin >> brr[i];
        sort(brr, brr+m);
        int k=arr[0];
        sort(arr, arr+n);
        for(int i=0; i<m; i++){
            if(brr[i]<=k){
                cnt[i]=0;
            }else{
                int p = lower_bound(arr, arr+n, brr[i]) - arr;
                if(p==n){
                    cnt[i]=0;
                }else{
                    cnt[i]=n-p;
                }
            }
        }
        sort(cnt, cnt+m);
        for(int i=1; i<=m; i++){
            int cnt1=0;
            for(int j=i; j<=m; j+=i){
                cnt1+=cnt[j-1]+1;
            }
            cout << cnt1 << " ";
        }
        cout << endl;
    }
}