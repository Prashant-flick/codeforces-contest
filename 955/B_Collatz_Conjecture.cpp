#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        while(k>0){
            int temp = x%y;
            if(temp==0){
                k--;
                x++;
                continue;
            }
            temp = (y-temp)%y;
            if(k>=temp){
                k-=temp;
                x+=temp;
                if(x==y){
                    x=1;
                    break;
                }
                while(x%y==0){
                    if(x==y){
                        x=1;
                        break;
                    }
                    x/=y;
                }
                if(x==1){
                    break;
                }
            }else{
                x+=k;
                k=0;
            }
        }

        if(k==0){
            cout << x << endl;
        }else{
            int cnt = k%(y-1);
            // cout << x << " " << k << endl;
            cout << x+cnt << endl;
        }
    }
}