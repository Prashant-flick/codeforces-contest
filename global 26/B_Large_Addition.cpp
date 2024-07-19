#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if(s[0]!='1' || s[n-1]=='9'){
            cout << "NO" << endl;
            continue;
        }
        bool flag=true;
        for (int i = 1; i < n-1; i++)
        {
            if(s[i]=='0'){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    
}