#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        string x,s;
        cin >> x >> s;
        if(x==s){
            cout << 0 << endl;
        }else{
            bool flag = false;
            int cnt=0;
            while(n<=m){
                if(x.find(s)!=-1){
                    flag = true;
                    break;
                }
                cnt++;
                x+=x;
                n+=n;
            }
             if(x.find(s)!=-1){
                flag=true;
            }
            if(flag){
                cout << cnt << endl;
            }else{
                if((x+x).find(s)!=-1){
                    flag=true;
                    cout << cnt+1 << endl;
                }else{
                    cout << -1 << endl;
                }
                
            }
        }

    }
    
    return 0;
}