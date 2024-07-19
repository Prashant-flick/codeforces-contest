#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        string s;
        cin >> s;
        vector<int> vec(7,0);
        for(int i=0; i<m; i++){
            vec[s[i]-'A']++;
        }

        int ans=0;
        for(int i=0; i<7; i++){
            if(vec[i]<n)ans+=n-vec[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}