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
            if(s[i]-'0'==prev){
                ans+=1;
            }else{
                if(s[i]-'0'>prev){
                    ans+=(s[i]-'0')-prev;
                    ans+=1;
                    prev=s[i]-'0';
                }
            }
        }
        cout << ans << endl;
        
    }
    
    return 0;
}