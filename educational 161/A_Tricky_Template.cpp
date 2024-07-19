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
        string a,b,c;
        cin >> a >> b >> c;
        bool flag = false;
        transform(a.begin(), a.end(), a.begin(), ::toupper); 
        transform(b.begin(), b.end(), b.begin(), ::toupper); 
        transform(c.begin(), c.end(), c.begin(), ::toupper); 

        for (int i = 0; i < n; i++)
        {
            if(a[i]==b[i] && a[i]!=c[i] || ((a[i])!=c[i] && b[i]!=c[i])){
                flag = true;
                break;
            }
        }
        
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}