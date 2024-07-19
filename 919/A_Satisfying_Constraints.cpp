#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mini=INT_MIN;
        int maxi=INT_MAX;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int a,b;
            cin >> a >> b;
            if(a==1){
                mini=max(mini,b);
            }else if(a==2){
                maxi=min(maxi,b);
            }else{
                vec.push_back(b);
            }
        }

        int ans = (maxi-mini)+1;
        if(ans<=0){
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < vec.size() ; i++)
        {
            if(vec[i]>=mini && vec[i]<=maxi){
                ans--;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}