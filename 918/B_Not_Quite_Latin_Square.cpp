#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> s[i];
            for (int j = 0; j < 3; j++)
            {
                if(s[i][j]=='?'){
                    // cout << s[i].find("A") << endl;
                    if (s[i].find("A")==string::npos)
                    {
                        cout << 'A' << endl;
                    }else if(s[i].find("B")==string::npos){
                        cout << 'B' << endl;
                    }else{
                        cout << 'C' << endl;
                    }
                    break;
                }
            }
                        
        }
    }
    
    return 0;
}