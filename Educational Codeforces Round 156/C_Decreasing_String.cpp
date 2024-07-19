#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        long long pos;
        cin >> s >> pos;
        long long n = s.size();
        long long x=0;
        while(pos>n){
            pos-=n;
            n--;
            x++;
        }
        // cout << pos << " " << x << endl;

        string temp="";
        int i=0;
        n=s.size();
        while(i<n && x>0){
            if(temp.size()>0){
                while(temp.size()>0 && temp[temp.size()-1]>s[i])
                {
                    temp.pop_back();
                    x--;
                    if(x==0){
                        break;
                    }
                }
            }
            temp+=s[i];
            i++;
        }
        while (x>0)
        {
            temp.pop_back();
            x--;
        }
        while (i<n)
        {
            temp+=s[i];
            i++;
        }
        // cout << temp << " " << pos << endl;
        cout << temp[pos-1];
    }
    
    return 0;
}
