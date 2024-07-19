#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define int long long

int32_t main() { 
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int ans=0;
        int xoro=0;
        bool flag1=true;
        int and1=0;
        for(int i=0; i<n; i++){
            xoro^=arr[i];
            if(i==n-1){
                if((xoro|and1)>x){
                    flag1=false;
                }
            }
            if((xoro|and1)<=x){
                ans++;
                and1|=xoro;
                xoro=0;
            }
        }

        int ans2=0;
        bool flag2=true;
        xoro=0;
        int and2=0;
        for (int i = n-1; i>=0; i--)
        {
            xoro^=arr[i];
            if(i==0){
                if((xoro|and2)>x){
                    flag2=false;
                }
            }
            if((xoro|and2)<=x){
                ans2++;
                and2|=xoro;
                xoro=0;
            }
        }

        if(flag1 && flag2){
            ans = max(ans,ans2);
            cout << ans  << endl;
        }else if(flag1){
            cout << ans << endl;
        }else if(flag2){
            cout << ans2 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}