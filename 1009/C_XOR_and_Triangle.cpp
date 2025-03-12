#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,cnt=0;
        cin >> n;
        int arr[30]={0};
        for(int i=0; i<30; i++){
            if((1LL<<i)&n){
                arr[i]=1;
                cnt++;
            }
        }
        int f=1;
        int idx=30,idx1=30;
        for(int i=29; i>=0; i--){
            if(arr[i] && f){
                idx=i;
                f=0;
            }else if(!arr[i] && !f){
                f=1;
                idx1=i;
                break;
            }
        }
        if(cnt==1 || !f){
            cout << -1 << endl;
            continue;
        }
        int ans=(1LL<<idx1);
        for(int i=idx-1; i>=0; i--){
            if(arr[i]){
                ans+=(1LL<<i);
                break;
            }
        }
        cout << ans << endl;
    }
}