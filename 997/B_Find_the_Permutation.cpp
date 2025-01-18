#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n,-1);
        vector<string> vec(n+1);
        for(int i=1; i<=n; i++){
            cin >> vec[i];
        }

        for(int i=n; i>0; i--){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(vec[i][j]=='1' && j+1<i){
                    cnt++;
                }
            }
            
            int j=0;
            while(j<n){
                if(cnt==0 && ans[j]==-1){
                    ans[j]=i;
                    break;
                }
                if(ans[j]==-1){
                    cnt--;
                }
                j++;
            }
        }

        for(auto it: ans){
            cout << it << " ";
        }
        cout << endl;
    }
}