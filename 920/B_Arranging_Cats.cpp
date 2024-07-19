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
        string s1,s2;
        cin >> s1;
        cin >> s2;
        int ones1=0,ones2=0;
        for (int i = 0; i < n; i++)
        {
            if(s1[i]!=s2[i]){
                if(s1[i]=='1'){
                    ones1++;
                }else{  
                    ones2++;
                }
            }
        }
        if(ones1==0 && ones2==0){
            cout << 0 << endl;
        }else{
            cout << min(ones1,ones2)+abs(ones1-ones2) << endl;
        }
        
    }
    
    return 0;
}