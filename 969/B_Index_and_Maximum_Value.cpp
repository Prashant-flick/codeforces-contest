#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr[n];
        int maxi=INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi=max(maxi, arr[i]);
        }

        while(m--){
            char ch;
            int a,b;
            cin >> ch >> a >> b;
            if(ch=='+'){
                if(b>=maxi && a<=maxi){
                    maxi++;
                }
            }else{
                if(b>=maxi && a<=maxi){
                    maxi--;
                }
            }
            cout << maxi << " ";
        }
        cout << endl;
    }
}