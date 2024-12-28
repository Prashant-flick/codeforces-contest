#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    auto pot = [&](int a, int b) {
		int res = 1;
		while(b > 0) {
			if(b & 1) {
				res = (res * a) % MOD;
			}
			a = (a * a) % MOD;
			b /= 2;
		}
		return res;
	};

    int t;
    cin >> t;
    while(t--){
        int n,q,o,x;
        cin >> n >> q;
        int arr[n],brr[n];
        int arr1[n],brr1[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr1[i]=arr[i];
        }
        for(int i=0; i<n; i++){
            cin >> brr[i];
            brr1[i]=brr[i];
        }
        
        sort(arr, arr+n);
        sort(brr, brr+n);
        int ans=1;
        for(int i=0; i<n; i++){
            ans = (ans*min(arr[i],brr[i]))%MOD;
        }
        cout << ans << " ";
        while(q--){
            cin >> o >> x;
            if(o==1){
                int a = upper_bound(arr, arr+n, arr1[x-1])-arr;
                arr1[x-1]++;
                a--;
                arr[a]++;
                if(min(arr[a],brr[a])!=min(arr[a]-1,brr[a]-1)){
                    ans=(ans* pot(min(arr[a]-1,brr[a]), MOD-2)) % MOD;
                    ans=(ans*min(arr[a],brr[a]))%MOD;
                }
            }else{
                int a = upper_bound(brr, brr+n, brr1[x-1])-brr;
                brr1[x-1]++;
                a--;
                brr[a]++;
                if(min(brr[a],arr[a])!=min(brr[a]-1,arr[a]-1)){
                    ans=(ans * pot(min(brr[a]-1,arr[a]), MOD-2))%MOD;
                    ans=(ans*min(brr[a],arr[a]))%MOD;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}