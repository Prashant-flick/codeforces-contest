#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,odd=0,even=0;
        cin >> n;
        int arr[n];
        int ans=0;
        int osum=0,esum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]%2){
                odd++;
                osum+=arr[i];
            }else{
                even++;
                esum+=arr[i];
            }
            ans=max(ans,arr[i]);
        }
        if(even==0 || odd==0){
            cout << ans << endl;
        }else{
            ans=esum;
            ans+=osum-odd+1;
            cout << ans << endl;
        }
        
    }
}