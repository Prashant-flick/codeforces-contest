#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==b && b==c){
            cout << "YES" << endl;
        }else{
            int mini = min({a,b,c});
            if(a%mini==0 && b%mini==0 && c%mini==0){
                int cnt=0;
                cnt+=(a/mini-1);
                cnt+=(b/mini-1);
                cnt+=(c/mini-1);
                if(cnt<=3){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }else{
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}