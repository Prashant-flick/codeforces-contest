#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n-k<2){
            cout << "YES" << endl;
            continue;
        }
        vector<int> store(26,0);
        for (int i = 0; i < n; i++)
        {
            store[s[i]-'a']++;
        }
        int odd=0;
        int even=0;
        for (int  i = 0; i < store.size(); i++)
        {
            if(store[i]==0){
                continue;
            }
            if(store[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        if(k==odd){
            cout << "YES" << endl;
        }else if(k<odd){
            if(odd-k>1){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else{
            // if((k-odd)%2==0){
                cout << "YES" << endl;
            // }else{
            //     cout << "NO" << endl;
            // }
        }
        
    }
    
    return 0;
}