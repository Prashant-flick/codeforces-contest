#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a >> b;
        a = (a%b);
        int ans=0;
        int i=0;
        while (i<40)
        {
            if(a%b==0){
                break;
            }else{
                a = (a%b);
                ans+=a;
                a = (2*a)%b;
            }
            i++;
        }
        if(a%b==0){
            cout << ans << endl;
        }else{
            cout << min(-1,20) << endl;
        }
        
    }
    
    return 0;
}