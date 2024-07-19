#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while (t--)
    {
        int a,b;
        cin >> a >> b;
        int ans;
        for(int i=0; i<3; i++){
            int a1,b1;
            cin >> a1 >> b1;
            if(b==b1){
                a=abs(a-a1);
                ans=a*a;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}