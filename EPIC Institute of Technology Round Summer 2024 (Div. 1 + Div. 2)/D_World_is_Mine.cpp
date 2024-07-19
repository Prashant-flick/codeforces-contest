#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int n;
int maxi=0;

int solve(int *mp,int i, int cnt){
    if(i>=maxi+1){
        return 0;
    }
    if(dp[i][cnt]!=-1){
        return dp[i][cnt];
    }
    int taken=0, not_taken=0;
    if(mp[i]!=0){
        if(cnt>=mp[i]){
            taken = 1 + solve(mp, i+1, cnt-mp[i]);
        }
        not_taken = solve(mp, i+1, cnt+1);
    }else{
        not_taken = solve(mp, i+1, cnt);
    }

    return dp[i][cnt] = max(taken, not_taken);
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }

        for(int i=0; i<=maxi; i++){
            for(int j=0; j<=maxi; j++){
                dp[i][j]=-1;
            }
        }

        int mp[maxi+1]={0};
        set<int> st;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            st.insert(arr[i]);
        }

        int ans = solve(mp, 1, 0);
        cout << st.size()-ans << endl;
    }   
    
}