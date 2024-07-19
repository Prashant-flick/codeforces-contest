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
        int i;
        for (i = n-1; i>=0; i--)
        {
            if(s[i]=='B'){
                break;
            }
        }
        int cnt1=0;
        int cnt2=0;
        int ans=0;
        while (i>=0)
        {
            if(s[i]=='B'){
                if(cnt2>0){
                    ans+=cnt2-1;
                    cnt1=1;
                }
                cnt2=0;
                cnt1++;
            }else{
                ans+=cnt1;
                cnt1=0;
                cnt2++;
            }
            i--;
        }
        if(cnt2>0){
            ans+=cnt2-1;
        }
        cout << ans << endl;
    }
    
    return 0;
}