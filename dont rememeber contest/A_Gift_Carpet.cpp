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
        vector<string> store;
        int cnt=0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            store.push_back(s);
        }
        string p = "vika";
        int k=0;
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                string s = store[i];
                if(k<4 && s[j]==p[k]){
                    k++;
                    break;
                }
            }
            if(k==4){
                break;
            }
        }
        if(k==4){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    
    return 0;
}