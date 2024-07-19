#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1[2];
        cin >> s1[0] >> s1[1];
        int i=0,j=0;
        int path=1;
        string ans = "";
        ans+=s1[0][0];
        bool flag = false;
        while(j<n){
            if(j<n && s1[i][j+1] == '0' && s1[i+1][j] == '0'){
                path++;
                ans+='0';
                j++;
            }else if(j<n && s1[i][j+1] == '1' && s1[i+1][j] == '1'){
                path++;
                ans+='1';
                j++;
            }else if(j<n && s1[i][j+1] == '1' && s1[i+1][j] == '0'){
                while(j<n){
                    ans+=s1[1][j];
                    j++;
                }
                flag=true;
                break;
            }else if(j<n && s1[i][j+1] == '0' && s1[i+1][j] == '1'){
                path=1;
                ans+='0';
                j++;
            }else{
                j++;
            }
        }

        if(flag){
            cout << ans << endl;
            cout << path << endl;
        }else{
            ans+=s1[1][n-1];

            cout << ans << endl;
            cout << path << endl;
        }
        
    }
}