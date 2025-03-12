#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,maxi;
const int N = 2e5+10;
int arr[N],brr[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        maxi = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
            maxi = max(maxi, brr[i]);
        }

        int ans = 0;
        map<int,int> vec1[maxi*2+1];

        for (int i = 0; i < n; i++) {
            int a = arr[i];
            int c = brr[i], d = 0;

            for (int j1 = 0; j1 <= brr[i]; j1++) {
                int j = j1 + maxi;
                int j2 = -j1 + maxi;
                int l = a+(floor)(sqrt((brr[i]*brr[i])-(j1*j1)));
                int r = a - (l-a);
                swap(l,r);
                if(j==maxi){
                    vec1[j][l]++,vec1[j][r+1]--;
                }else{
                    vec1[j][l]++,vec1[j][r+1]--,vec1[j2][l]++,vec1[j2][r+1]--;
                }
            }
        }
        for(int i=0; i<maxi*2+1; i++){
            int l=0,cnt=0;
            for(auto it: vec1[i]){
                if(cnt==0){
                    l=it.first;
                }
                cnt+=it.second;
                if(cnt==0){
                    ans+=it.first-l;
                    l=it.first;
                }
            }
        }
        cout << ans << endl;
    }
}
