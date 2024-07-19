#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = s.length();
        int count=0;
        bool change = 0;
        if(len%2!=0){
            change = 1;
        }else{
            if(s[0]==')'){
                change = 1;
            }else{
                for (int i = 0; i < len; i++)
                {   
                    if(count<0){
                        change = 1;
                        break;
                    }
                    if(s[i]=='('){
                        count++;
                    }else{
                        count--;
                    }
                }
                if(count>0){
                    change = 1;
                }
            }
        }
        if(change){
            cout << "YES" << endl;
            string y;
            if(len%2==0){
                if(s[0]=='(' && s[1]=='(' || s[0]==')' && s[1]==')'){
                    y+="()()";
                }
                if(s[0]=='(' && s[1]==')' || s[0]==')' && s[1]=='('){
                    y+="(())";
                }
                for (int i = 2; i <len; i++)
                {
                    y+="()";
                }
                
            }else{
                for (int i = 0; i < len; i++)
                {
                    y+='(';
                }
                for (int i = 0; i < len; i++)
                {
                    y+='(';
                }  
            } 
            cout << y << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}