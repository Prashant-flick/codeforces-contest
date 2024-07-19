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
        int plus=0,minus=0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='-'){
                minus++;
            }else{
                plus++;
            }
        }
        plus = abs(plus-minus);
        cout << plus << endl;
    }
    
    return 0;
}