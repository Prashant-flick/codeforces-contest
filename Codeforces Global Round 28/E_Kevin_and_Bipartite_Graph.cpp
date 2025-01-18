#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if(n>=m){
            cout << "YES" << endl;
            for(int i=0; i<2*n; i++){
                for(int j=1; j<=m; j++){
                    cout << j << " ";   
                }
                cout << endl;
            }
        }else if(2*n>m){
            cout << "YES" << endl;
            int arr[n][m];
            int a = 1;
            int cnt=0;
            for(int i=0; i<n; i++){
                a=i+1;
                cnt=0;
                for(int j=0; j<m; j++){
                    cout << a << " ";
                    cnt++;
                    if(cnt==2){
                        a=(a+1)%(n+1);
                        if(a==0)a++;
                        cnt=0;
                    }
                }
                cout << endl;
            }
            a=1;
            cnt=1;
            for(int i=0; i<n; i++){
                a=i+1;
                cnt=1;
                for(int j=0; j<m; j++){
                    cout << a << " ";
                    cnt++;
                    if(cnt==2){
                        a=(a+1)%(n+1);
                        if(a==0)a++;
                        cnt=0;
                    }
                }
                cout << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }
}