#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = false;
        int res=0;
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                if(flag){
                    break;
                }
                flag = true;
            }else{
                if(s[i]=='@'){
                    res++;
                }
                flag=false;
            }
        }

        cout << res << endl;
    }
    return 0;
}