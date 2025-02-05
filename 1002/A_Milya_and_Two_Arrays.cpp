#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n],brr[n];
        set<int> st1;
        set<int> st2;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            st1.insert(arr[i]);
        }
        for(int i=0; i<n; i++){
            cin >> brr[i];
            st2.insert(brr[i]);
        }
        if((st1.size()==1 && st2.size()<=2) || (st1.size()<=2 && st2.size()==1)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    
}