#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        string x,y;
        cin >> x >> y;
        int n = x.size();

        bool flag=false;
        char ch;
        for(int i=0; i<n; i++){
            if(flag){
                if(ch=='x'){
                    if(y[i]<x[i]){
                        char temp = x[i];
                        x[i] = y[i];
                        y[i] = temp;
                    }
                }else if(ch=='y'){
                    if(x[i]<y[i]){
                        char temp = x[i];
                        x[i] = y[i];
                        y[i] = temp;
                    }
                }
            }
            else if(x[i] != y[i]){
                flag=true;
                if(x[i]>y[i]){
                    ch = 'x';
                }else{
                    ch = 'y';
                }
            }
        }

        cout << x << endl;
        cout << y << endl;
    }
    

    return 0;
}