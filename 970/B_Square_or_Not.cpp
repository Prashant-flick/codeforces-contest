#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag=false;
        int i=2;
        for(; i*i<=n; i++){
            if(i*i==n){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout << "No" << endl;
        }else{
            int tot = i*4 - 4;
            tot = n-tot;
            int l=0;
            flag=true;
            for(int j=0; j<i; j++){
                for(int k=0; k<i; k++){
                    if(j>0 && j<i-1 && k>0 && k<i-1){
                        if(s[l]!='0'){
                            flag=false;
                            break;
                        }
                    }else{
                        if(s[i]=='0'){
                            flag=false;
                            break;
                        }
                    }
                    l++;
                }
            }
            if(flag){
                cout <<"Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}