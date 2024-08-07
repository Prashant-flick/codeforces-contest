#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Mod 1000000007

int solve11(){
    vector<string> s(1);
    cin >> s[0];

    int n = s[0].size();
    int arr1[n+1]={0};
    int arr2[2*n+2]={0};

    int i=0;
    while(i<n){
        arr1[i+1] = arr1[i];

        arr1[i+1]+= (s[0][i] =='1' ? 1 : -1);
        i++;
    }

    i=1;
    int ans = 0;
    ans++;
    while(i<=n){
        arr2[arr1[i-1]+n]+=i;
        arr2[arr1[i-1]+n] = arr2[arr1[i-1]+n]%Mod;

        ans = (ans + arr2[arr1[i] + n] * (n-i+1)) % Mod;

        i++;
    }

    ans = ans-1;

    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin >> t;
    while (t--) {
        int res = solve11();
        cout << res << endl;
    }
    return 0;
}