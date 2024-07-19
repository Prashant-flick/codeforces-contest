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
        int arr[n+1];
        for(int i=1; i<=n; i++)cin >> arr[i];

        int cnt=0;
        int i=1;
        while(i<n){
            if(arr[i]==i || (arr[i]%2 == i%2) && (arr[i]<i) && (i-(cnt*2))<=arr[i]){
                int cnt1=0;
                while(i<n && arr[i]==i || (arr[i]%2 == i%2) && (arr[i]<i) && (i-(cnt*2))<=arr[i]){
                    cnt1++;
                    i++;
                }
                if((n+1)-i >= cnt1){
                    cnt+=cnt1;
                    i--;
                    i+=cnt1;
                }else{
                    cnt+=(cnt1+((n+1)-i))/2;
                    i--;
                    i+=(cnt1+((n+1)-i))/2;
                }
            }
            i++;
        }
        cout << cnt << endl;
    }
    
}