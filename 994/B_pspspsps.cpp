#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i=0;
        int j=n-1;
        while(i<n && s[i]=='.'){
            i++;
        }
        while(j>=0 && s[j]=='.'){
            j--;
        }
        if(i==j || i==n || j<0){
            cout << "YES" << endl;
        }else if(s[i]=='p' && s[j]=='s'){
            cout << "NO" << endl;
        }else{
            int i=0;
            while(i<n && s[i]=='p'){
                i++;
            }
            if(i==n){
                cout << "YES" << endl;
                continue;
            }
            i=0;
            while(i<n && s[i]=='s'){
                i++;
            }
            if(i==n){
                cout << "YES" << endl;
                continue;
            }
            bool flag1=false;
            for(int i=1; i<n; i++){
                if(s[i]=='s'){
                    flag1=true;
                    break;
                }
            }
            bool flag2=false;
            for(int i=n-2; i>=0; i--){
                if(s[i]=='p'){
                    flag2=true;
                    break;
                }
            }
            if(flag1 && flag2){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }
}