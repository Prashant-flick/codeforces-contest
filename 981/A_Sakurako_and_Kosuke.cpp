#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i=1;
        int cnt=0;
        for(; i<n; i++){
            int a = 2*i-1;
            if(i%2==1){
                cnt-=a;
                if(cnt<-n){
                    break;
                }
            }else{
                cnt+=a;
                if(cnt>n){
                    break;
                }
            }
        }
        if(i%2==0){
            cout << "Sakurako" << endl;
        }else{
            cout << "Kosuke" << endl;
        }
    }
}