#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ones=0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]-'0'==1){
                ones++;
            }
        }
        int i=0;
        int cnt=0;
        int j=n-1;
        int k=j;
        for(i=0; i<(n-ones); i++){
            if(s[j]-'0'==0){
                cout << cnt << " ";
            }else{
                if(k>j){
                    k=j;
                }
                while((s[k]-'0')==1){
                    k--;
                }
                cnt+=(j-k);
                cout << cnt << " ";
                swap(s[k],s[j]);
            }
            j--;
        }
        while (i<n)
        {
            cout << -1 << " ";
            i++;
        }
        cout << endl;
        
    }
    
    return 0;
}