#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        string a,b;
        cin >> a>> b;
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        for(int i=0; i<n; i++){
            if(i%2){
                if(a[i]=='1'){
                    cnt1++;
                }
                if(b[i]=='0'){
                    cnt2++;
                }
            }else{
                if(a[i]=='1'){
                    cnt3++;
                }
                if(b[i]=='0'){
                    cnt4++;
                }
            }
        }
        if(cnt1<=cnt4 && cnt3<=cnt2){
            cout << "YES" << endl;
        }else{
            cout << "NO"<< endl;
        }
    }
}