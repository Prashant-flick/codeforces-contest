#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a = "aeiou";
        if(n<=5){
            cout << a.substr(0,n) << endl;
            continue;
        }
        int b = n/5;
        int c = n%5;
        int i=0;
        int k=0;
        string s;
        while(i<5){
            int j=0;
            while(j<b+(c>0 ? 1:0)){
                s+=a[k];
                j++;
            }
            c--;
            k++;
            i++;
        }
        cout << s << endl;
    }
    
}