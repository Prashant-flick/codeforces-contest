#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s;
        int cnt=0;
        int ans=0;
        while(n--){
            cin >> s;
            cnt+=s.size();
            if(cnt<=m){
                ans++;
            }
        }
        cout << ans << endl;
    }
}