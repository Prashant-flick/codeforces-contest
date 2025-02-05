#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        vector<int> ans;

        bool flag=true;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=n-1; j>=0; j--){
                if(arr[i][j]==1){
                    cnt++;
                }else{
                    break;
                }
            }
            if(cnt==0){
                if(flag){
                    ans.push_back(cnt);
                }
                flag=false;
                continue;
            }
            ans.push_back(cnt);
        }
        sort(ans.begin(), ans.end());
        int j=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]>=j){
                j++;
                continue;
            }

        }
        cout << min(j,n) << endl;
    }
    
}