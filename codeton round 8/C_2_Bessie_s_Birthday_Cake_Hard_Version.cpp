#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        int ans=x-2;
        int arr[x];
        for(int i=0; i<x; i++){
            cin >> arr[i];
        }

        if(x+y>=n){
            cout << n-2 << endl;
            continue;
        }

        int cnt=0;
        sort(arr, arr+x);
        vector<int> brr;
        for(int i=0; i<x-1; i++){
            if(arr[i+1]-arr[i]==2){
                ans++;
            }else if(arr[i+1]-arr[i]>2){
                brr.push_back(arr[i+1]-arr[i]);
            }
        }
        if((n-arr[x-1]+arr[0]) == 2){
            ans++;
        }else if((n-arr[x-1])+arr[0]>2){
            brr.push_back((n-arr[x-1])+arr[0]);
        }

        sort(brr.begin(), brr.end());
        for(int i=0; i<brr.size(); i++){
            if(brr[i]%2==0){
                if(y>=brr[i]/2-1){
                    ans+=brr[i]-1;
                    y-=brr[i]/2-1;
                }else{
                    ans+=y*2;
                    y=0;
                }
            }else{
                cnt+=(brr[i]-1)/2;
            }
        }
        
        if(y>0 && cnt>0){
            if(y>=cnt){
                ans+=cnt*2;
            }else{
                ans+=y*2;
            }
        }

        cout << ans << endl;
    }
    return 0;
}