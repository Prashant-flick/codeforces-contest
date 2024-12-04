#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if(n==1){
            cout << -1 << endl;
            continue;
        }
        string t="";
        string t2="";
        for(int i=0; i<n; i++){
            if(i<n-1 && s[i]==s[i+1]){
                t+=s[i];
                t+=s[i];
                break;
            }
            if(i<n-2 && s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]){
                t2+=s[i];
                t2+=s[i+1];
                t2+=s[i+2];
                break;
            }
        }

        if(t.size()>0){
            cout << t << endl;
            continue;
        }
        if(t2.size()>0){
            cout << t2 << endl;
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}