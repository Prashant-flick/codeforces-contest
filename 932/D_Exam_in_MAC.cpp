#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,l;
        cin >> n >> l;
        l++;
        // cout << l << endl;
        int res = ((l)*(l+1))/2;
        // cout << res << endl;
        int odd=0;
        int even=0;
        for(int i=0; i<n ;i++){
            int temp;
            cin >> temp;
            int a,b;
            a = (temp)/2+1;
            b = (l-1)-temp;
            if(temp%2==0){
                res -= (a+b-even);
                even++;
            }else{
                res -= (a+b-odd);
                odd++;
            } 
        }

        cout << res << endl;
    }
    return 0;
}