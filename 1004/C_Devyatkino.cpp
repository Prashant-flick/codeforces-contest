#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int store[16][10];
    int num=9;
    for(int i=0; i<16; i++){
        if(i>0){
            num+=((pow(10,i))*9);
        }
        for(int j=0; j<10; j++){
            store[i][j]=((j==0)?num:store[i][j-1]+num);
        }
    }
    
    int t;cin>> t;
    while(t--){
        int n;
        cin >> n;
        int num=n;
        int ans=20;
        while (num>0)
        {
            if(num%10==7){
                ans=min(ans,0LL);
            }
            num/=10;
        }
        for(int i=0; i<16; i++){
            num=n;
            for(int j=0; j<10; j++){
                num=n+store[i][j];
                while(num>0){
                    if(num%10==7){
                        ans=min(ans,j+1);
                    }
                    num/=10;
                }
            }
        }
        cout << ans << endl;
    }
}