#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int pre[n];
        int ans=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i==0){
                pre[i]=1;
            }else{
                if(arr[i]>pre[i-1]){
                    pre[i]=pre[i-1]+1;
                    ans=max(pre[i],ans);
                }else if(arr[i]==pre[i-1]){
                    pre[i]=pre[i-1];
                }else{
                    pre[i]=pre[i-1]-1;
                }
            }
        }

        for(int i=0; i<n; i++){
            cout << pre[i]<< " ";
        }
        cout << endl;

        int i=0;
        while(i<n-1 && pre[i]==pre[i+1]){
            i++;
        }
        int l=-1,r=-1;
        int maxi=INT_MIN;
        while(i<n-1){
            if(i<n-1 && pre[i]>=pre[i+1]){
                int cnt=0;
                int k=i;
                while(i<n-1 && pre[i]>=pre[i+1]){
                    if(pre[i]>pre[i+1]){
                        cnt++;
                    }
                    i++;
                }
                if(cnt>maxi){
                    l=k+1;
                    r=i;
                    maxi=cnt;
                }
            }else if(i<n-1 && pre[i]<=pre[i+1]){
                while(i<n-1 && pre[i]<=pre[i+1]){
                    i++;
                }
            }
        }

        if(maxi==INT_MIN){
            cout << pre[n-1]-1 << endl;
            continue;
        }

        pre[0]=1;
        for(int i=1; i<n; i++){
            if(i>=l && i<=r){
                pre[i]=pre[i-1];
                continue;
            }
            if(arr[i]>pre[i-1]){
                pre[i]=pre[i-1]+1;
            }else if(arr[i]==pre[i-1]){
                pre[i]=pre[i-1];
            }else{
                pre[i]=pre[i-1]-1;
            }
        }

        if(r==n-1){
            cout << max(ans,pre[l-1]) << endl;
        }else{
            cout << max(ans,pre[n-1]) << endl;
        }
    }
}
