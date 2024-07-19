#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> brr(m);
        for (int i = 0; i < m; i++)
        {
            cin >> brr[i];
        }
        sort(arr.begin(), arr.end());
        sort(brr.rbegin(), brr.rend());
        int i=0;
        int j=m-1;
        int k=0;
        int l=n-1;
        int ans = 0;
        while(i<=l){
            // cout << arr[i] << " " << brr[k] << " " << brr[j] << " " << arr[l] << endl;
            if(abs(arr[i]-brr[k])>=abs(brr[j]-arr[l])){
                ans+=abs(arr[i]-brr[k]);
                k++;
                i++;
            }else{
                ans+=abs(brr[j]-arr[l]);
                l--;
                j--;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}