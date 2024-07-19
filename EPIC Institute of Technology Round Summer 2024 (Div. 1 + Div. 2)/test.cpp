// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int n,m;

int solve(int *size, int *taste, int i, int sum, int mini, int s){
    if(i>=n || s>=m){
        return 0;
    }

    int taken=0;
    if(mini>taste[i]){
        taken = (size[i]*taste[i]) - (sum*(mini-taste[i])) + solve(size, taste, i+1, sum+size[i], min(mini, taste[i]), s+1);
    }else{
        taken = (size[i]*mini) + solve(size, taste, i+1, sum+size[i], min(mini, taste[i]), s+1);
    }
    int not_taken = solve(size, taste, i+1, sum, mini, s);
    return max(taken, not_taken);
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int size[n];
        int taste[n];
        for (int i = 0; i < n; i++)
        {
            cin >> size[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> taste[i];
        }

        cout << solve(size, taste, 0, 0, 1e6, 0);
        
    }
    

    return 0;
}