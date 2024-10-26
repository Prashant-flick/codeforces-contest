#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        string s,p;
        cin >> s >> p;
        int n=s.size();
        int m=p.size();
        int i=0;
        for(; i<min(n,m); i++){
            if(s[i]!=p[i]){
                break;
            }
        }
        cout << (i>0?i+1:0)+(n-i)+(m-i) << endl;
    }
}