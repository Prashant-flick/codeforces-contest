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
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        int frow=0;
        int lrow=n-1;
        int fcol=0;
        int lcol=n-1;
        long long totcnt = 0;
        int n1=n;
        while(n1>=2){
            for (int i = fcol; i < lcol; i++)
            {
                int x=frow;
                int y=i;
                char ch=s[x][y];
                for (int j = 0; j < 3; j++)
                {
                    int temp=x;
                    x=y;
                    y=(n-1)-temp;
                    if(ch<s[x][y]){
                        ch=s[x][y];
                    }
                }
                int cnt=0;
                x=frow;
                y=i;
                for(int j=0; j<4; j++){
                    // cout << ch << " " << s[x][y] << endl;
                    // cout << ch-s[x][y] << endl;
                    if(ch>s[x][y]){
                        cnt+=ch-s[x][y];
                    }
                    int temp=x;
                    x=y;
                    y=(n-1)-temp;
                }
                // cout << cnt << endl;
                totcnt+=cnt;
            }
            n1-=2;
            fcol++;
            lcol--;
            frow++;
        }
        cout << totcnt << endl;
    }
    
    return 0;
}