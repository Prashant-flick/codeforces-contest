#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void rightshift(string &s, int k){
    int j=0;
    int temp1=s[0];
    int temp2=s[0];
    for (int i = 0; i < k; i++)
    {
        j=(j+k)%n;
        temp2=s[j];
        s[j]=temp1;
        temp1=temp2;
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> n >> k;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        if(k==1){
            cout << "YES" << endl;
        }else{
            reverse(s.begin(), s.end()); 
            unordered_map<string,bool> mp;
            mp[s]=true;
            bool flag = false;
            while (k--)
            {
                flag = false;
                for (int i = 0; i < n; i++)
                {
                    if(s[i]-'0'==i+1){
                        rightshift(s,i+1);
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(!flag){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }
    
    return 0;
}