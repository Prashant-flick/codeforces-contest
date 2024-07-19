#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        set<int> st;
        int ans=0;
        for (int i = 0; i < n; i++)
        {
            if(st.find(arr[i])==st.end()){
                ans+=(n-i);
            }
            st.insert(arr[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}