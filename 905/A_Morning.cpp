#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ans=0;
        int prev = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int t=s[i]-'0';
            if(t==0){
                t=10;
            }
            if(t==prev){
                ans+=1;
            }else if(t>prev){
                ans+=(t)-prev;
                ans+=1;
                prev=t;
            }else{
                ans+=(prev)-(t);
                ans+=1;
                prev=t;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}