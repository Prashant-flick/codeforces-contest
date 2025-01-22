#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,l,r;
    cin >> n >> l >> r;
    l--;r--;
    int arr[n];
    vector<int> mp;
    vector<int> mp1;
    vector<int> mp2;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >>arr[i];
        if(i>=l && i<=r){
            mp.push_back(arr[i]);
            ans+=arr[i];
        }else if(i<l){
            mp1.push_back(arr[i]);
        }else{
            mp2.push_back(arr[i]);
        }
    }

    sort(mp.rbegin(), mp.rend());
    sort(mp1.begin(), mp1.end());
    sort(mp2.begin(), mp2.end());
    int ans1=ans;
    int ans2=ans;
    int a=mp.size();
    int b=mp1.size();
    int c=mp2.size();
    for(int i=0; i<a&&i<b; i++){
        if(mp1[i]<mp[i]){
            ans1-=(mp[i]-mp1[i]);
        }else{
            break;
        }
    }

    for(int i=0; i<a&&i<c; i++){
        if(mp2[i]<mp[i]){
            ans2-=(mp[i]-mp2[i]);
        }else{
            break;
        }
    }
    
    cout << min(ans1,ans2) << endl;
}

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}