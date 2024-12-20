#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        if(n%2==0){
            if((abs(x-y))%2){
                for(int i=0; i<n; i++){
                    cout << (i%2==0?0:1) << " ";
                }
                cout << endl;
            }else{
                for(int i=0; i<n; i++){
                    if(i+1==x){
                        cout << 2 << " ";
                    }else{
                        cout << (i%2==0?0:1) << " ";
                    }
                }
                cout << endl;
            }
        }else{
            if((abs(x-y))%2){
                for(int i=0; i<n-1; i++){
                    cout << (i%2==0?0:1) << " ";
                }
                cout << 2 << endl;
            }else{
                int i=1;
                bool flag=true;
                while(i<=n){
                    if(i==x+1){
                        cout << 2 << " ";
                        flag=false;
                    }else{
                        if(flag){
                            cout << (i%2==0?0:1) << " ";
                        }else{
                            cout << (i%2==0?1:0) << " ";
                        }
                    }
                    i++;
                }
                cout << endl;
            }
        }
    }
}