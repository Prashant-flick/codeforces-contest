#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                break;
            }
        }

        if(i>=j){
            cout << s << endl;
        }else{
            // cout << i << " " << j << endl;
            if(s[i]<s[j]){
                cout << s << endl;
            }else{
                string ans = s;
                reverse(s.begin(), s.end());
                s+=ans;
                cout << s << endl;
            }
        }
    }
}