#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define fi first
#define se second
#define pii pair<int,int>
const int MOD = 1e9 + 7;

void Solve()
{
    int n; cin >> n;
    vector <vector <char>> g(2 , vector <char>(n));
    for(auto &x : g){
        for(auto &y : x) cin >> y;
    }
    int ans = 0;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < n ; j++){
            if(g[i][j] == '.'){
                if(i == 0){
                    if(g[i + 1][j] == '.'){
                        if((j - 1 >= 0 && g[i + 1][j - 1] == 'x' && g[i][j - 1] == '.') && (j + 1 < n && g[i + 1][j + 1] == 'x' && g[i][j + 1] == '.')){
                            ans++;
                        }
                    }
                }
                else{
                    if(g[i - 1][j] == '.'){
                        if((j - 1 >= 0 && g[i - 1][j - 1] == 'x' && g[i][j - 1] == '.') && (j + 1 < n && g[i - 1][j + 1] == 'x' && g[i][j + 1] == '.')){
                            ans++;
                        } 
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
int32_t main()
{

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }
    return 0;
}