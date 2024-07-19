#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];
int solve(vector<int> &h, int i, int j){
    if(i==0){
        return (h[0]-1)*j;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j] = min(solve(h, i-1, j) , (h[i]-1)*j+i+solve(h, i-1, i));
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        set<int> s;
        for (int i = 0; i <=n; i++)
        {
            s.insert(i);
        }
        for(int i=0; i<n; i++){
            cin >> arr[i];
            s.erase(arr[i]);
        }
        int mex = *s.begin();
        if(mex==0){
            cout << 0 << endl;
        }else{
            vector<int>h(mex,0);
            //hashing
            for(int i=0; i<n; i++){
                if(arr[i]<mex){
                    h[arr[i]]++;
                }
            }
            for (int i = 0; i < mex; i++)
            {
                for (int j = 0; j <= mex; j++)
                {
                    dp[i][j]=-1;
                }
                
            }
            
            cout << solve(h, mex-1, mex) << endl;
        }
    }
    
    return 0;
}