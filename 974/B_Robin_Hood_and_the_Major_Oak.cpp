#include<bits/stdc++.h>
using namespace std;

// #define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;

        int temp = n-(n-k);
        if(temp%2==0){
            if((temp/2)%2==0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(temp%2==1){
            if(n%2==1){
                if(((temp+1)/2)%2==0){
                cout << "YES" << endl;
                }else{
                    cout << "NO"<< endl;
                }
            }else{
                if(((temp+1)/2)%2==1){
                    cout << "YES" << endl;
                }else{
                    cout << "NO"<< endl;
                }
            }
        }
    }
}