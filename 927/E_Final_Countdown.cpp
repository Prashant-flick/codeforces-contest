#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;
        for(int i=0; i<n-1; i++){
            sum += (s[i]-'0');
        }

        
        int num = (s[n-1]-'0')+sum;
        int carry = num/10;
        int rem = num%10;
        rem+=48;
        s[n-1]= rem;
        for(int i=n-2; i>=0; i--){
            num = (s[i]-'0')+carry;
            sum-=(s[i]-'0');
            num+=sum;
            carry = num/10;
            rem = num%10;
            num+=rem;
            s[i] = (rem+48);
        }

        int i=0;
        for(i=0; i<n; i++){
            if(s[i]!='0') break;
        }


        if(carry==1){
            cout << 1 << s << endl;
        }else{
            cout << s.substr(i, n-i) << endl;
        }
    }
    return 0;
}