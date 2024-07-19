#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        int a[n][m];
        int b[n][m];
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            for(int j=0; j<m; j++){
                a[i][j]=s[j]-'0';
            }
        }
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            for(int j=0; j<m; j++){
                b[i][j]=s[j]-'0';
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << a[i][j];
        //     }
        //     cout << endl;
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << b[i][j];
        //     }
        //     cout << endl;
        // }

        bool flag=true;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                // cout << a[i][j] << " " << b[i][j] << endl;
                if(a[i][j]!=b[i][j] && j==m-1){
                    flag=false;
                    break;
                }else if(j==m-1 && a[i][j]!=b[i][j]){
                    continue;
                }
                if(a[i][j]!=b[i][j]){
                    if(b[i][j]<a[i][j]){
                        int temp = a[i][j]-b[i][j] == 1 ? 2 : 1;
                        int temp2 = temp==1 ? 2 : 1;
                        a[i][j]=(a[i][j]+temp)%3;
                        a[i+1][j+1]=(a[i+1][j+1]+temp)%3;
                        a[i][j+1]=(a[i][j+1]+temp2)%3;
                        a[i+1][j]=(a[i+1][j]+temp2)%3;
                    }else{
                        int temp = b[i][j]-a[i][j];
                        int temp2 = temp==1? 2:1;
                        a[i][j]=(a[i][j]+temp)%3;
                        a[i+1][j+1]=(a[i+1][j+1]+temp)%3;
                        a[i][j+1]=(a[i][j+1]+temp2)%3;
                        a[i+1][j]=(a[i+1][j]+temp2)%3;
                    }
                }
            }
            if(!flag){
                break;
            }
        }

        if(!flag){
            cout << "NO" << endl;
            continue;
        }

        for(int j=0; j<m; j++){
            if(a[n-1][j]!=b[n-1][j]){
                flag=false;
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
}