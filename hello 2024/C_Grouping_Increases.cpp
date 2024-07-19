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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if(n<=2){
            cout << 0 << endl;
            continue;
        }
        
        vector<int> a;
        a.push_back(arr[n-1]);
        vector<int> b;
        b.push_back(0);
        int j=0;
        int k=0;
        for (int i = n-2; i >=0 ; i--)
        {
            if(arr[i]>=a[j]){
                a.push_back(arr[i]);
                j++;
            }else if(arr[i]>=b[k]){
                b.push_back(arr[i]);
                k++;
            }else if((a[j]-arr[i])>(b[k]-arr[i])){
                b.push_back(arr[i]);
                k++;
            }else{
                a.push_back(arr[i]);
                j++;
            }
        }
        int ans=0;
        for (int i = 1; i < a.size() ; i++)
        {
            if(a[i]<a[i-1])ans++;
        }
        for (int i = 2; i < b.size() ; i++)
        {
            if(b[i]<b[i-1])ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}