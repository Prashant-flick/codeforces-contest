#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int solve(int i, int *arr, int *dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int taken=INT_MAX,not_taken=INT_MAX;
    if(i+arr[i]<n){
        taken = solve(i+arr[i]+1, arr, dp);
    }
    not_taken = 1+solve(i+1, arr, dp);
    return dp[i]=min(taken, not_taken);
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, arr, dp);
        cout << ans << endl;
    }
    
    return 0;
}