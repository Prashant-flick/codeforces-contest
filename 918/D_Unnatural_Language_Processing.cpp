#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        int i=0;
        while (i < n)
        {
            for (int j = 0; j < 2 && i<n; j++)
            {
                ans+=s[i];
                i++;
            }
            if(i==n-1 && i<n){
                ans+=s[i];
                break;
            }
            else if(i<n-1 && (s[i]!='a' && s[i]!='e') && (s[i+1]!='a' && s[i+1]!='e')){
                ans+=s[i];
                i++;
            }
            if(i!=n){
                ans+='.';
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}