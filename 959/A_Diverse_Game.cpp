#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        // unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
                // mp[arr[i][j]]++;
            }
        }

        int p = n*m/2;

        if(n*m==1){
            cout << -1 << endl;
            continue;
        }
        // if(maxi>p){
        //     cout << -1 << endl;
        //     continue;
        // }


        if(m==1){
            for(int j=0; j<m; j++){
                for(int i=1; i<n; i++){
                    cout << arr[j][i] << endl;
                }
                cout << arr[j][0] << endl;
            }
        }else{
            for(int i=0; i<n; i++){
                for(int j=1; j<m; j++){
                    cout << arr[i][j] << " ";
                }
                cout << arr[i][0] << endl;
            }
        }

        
    }
    return 0;
}