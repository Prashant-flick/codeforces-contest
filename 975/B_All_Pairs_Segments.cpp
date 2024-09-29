#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int ans[n]={0};
        ans[0]=ans[n-1]=n-1;
        int m=n-1;
        unordered_map<int,int> mp;
        mp[n-1]=2;
        for(int i=1; i<(n+1)/2; i++){
            ans[i]=ans[i-1]+m-i;
            ans[n-i-1]=ans[i];
            if((n-i-1) == i){
                mp[ans[i]]++;
                m--;
                continue;
            }
            mp[ans[i]]+=2;
            m--;
        }


        for(int i=1; i<n; i++){
            int temp = arr[i]-arr[i-1]-1LL;
            if(temp==0)continue;
            mp[ans[i-1]-(i-1)]+=temp+0LL;
        }

        // for(int i=n-2; i>=n/2; i--){
        //     int temp = arr[i+1]-arr[i]-1;
        //     if(temp==0)continue;
        //     mp[ans[i+1]-(n-(i+2))]+=temp;
        // }

        while(q--){
            int x;
            cin >> x;
            cout << mp[x] << " ";
        }
        cout << endl;
    }
    
    
}