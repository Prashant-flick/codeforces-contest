#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

int solve(int *arr, int i, int j, int p){
    if(i>=n){
        return 0;
    }

    int taken=0;
    int taken1=0;
    // cout << arr[i] << " " << i << " " << j << " " << p << endl;
    if(arr[i]==j){
        // cout << "here1 " << p << endl;
        int cnt=0;
        int k=i;
        int l=j;
        for(; k<=n; k++){
            if(arr[k]==l){
                cnt++;
            }else{
                break;
            }
            l++;
        }
        // cout << cnt << " "<< n << " "<< k << endl;
        if(cnt>1){
            if(n-k >= cnt){
                taken = cnt+solve(arr, i+cnt*2,  (i+2)-((p+cnt)*2), p+cnt);
            }else{
                taken = (cnt+((n+1)-k))/2 + solve(arr, n, n, n);
            }
        }
        taken1 = 1+solve(arr, i+2, (i+2)-((p+1)*2), p+1);
        // cout << "here1 " << p << endl;
    }
    int not_taken = solve(arr, i+1, j+1, p); 
    return max(taken, max(not_taken, taken1));
}

int32_t main(){
    int t;
    cin >> t;   
    while (t--)
    {
        cin >> n;
        int arr[n+1];
        for(int i=1; i<=n; i++)cin >> arr[i];

        int ans = 0;
        cout << solve(arr, 1, 1, 0) << endl;
    }
    
}