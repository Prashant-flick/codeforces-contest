#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int x,m;
        cin >> x >> m;
        int ans=0;
        unordered_map<int,bool> checked;
        for(int i=1; i<x; i++){
            if(x%i==0){
                int sum=0;
                for(int j=0; j<22; j++){
                    if(((1<<j)&x)!=((1<<j)&i)){
                        sum+=(1<<j);
                    }
                }
                if(sum<=m){
                    ans++;
                    checked[sum]=true;
                }
            }
        }

        int maxi = (32-(__builtin_clz(x)));
        maxi = (1<<maxi);

        for(int i=1; i<maxi; i++){
            if(i<=m && (i^x)!=0 && ((x%(i^x))==0 || (i%(i^x))==0) && (checked.find(i)==checked.end())){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}