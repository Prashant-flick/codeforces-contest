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
        vector<int> arr(n);
        for (int i = 0; i <n; i++)
        {
            cin >> arr[i];
        }
        if(n<3){
            cout << 0 << endl;
            continue;
        }

        sort(arr.begin(), arr.end());
        int ans=0;
        int i=1;    
        int cnt=0;
        while (i < n-1)
        {
            if(arr[i]==arr[i+1]){
                cnt+=i;
                ans+=cnt;
            }else{
                cnt=0;
            }
            i++;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}