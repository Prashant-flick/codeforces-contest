#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = (int)1e6+5;
const int N = (int)1e6;
int dp[MAXN], mc[MAXN];
ll ans=0;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int n,m;
    cin >> n >> m;
    int arr[n];
    int brr[n];
    for(int i=0; i<n; i++)cin >> arr[i];
    for(int i=0; i<n; i++)cin >> brr[i];

    memset(mc, 60, sizeof(mc));
    for(int i=0; i<n; i++){
        mc[arr[i]] = min(mc[arr[i]], arr[i]-brr[i]);
    }

    for(int i=1; i<=N; i++){
        mc[i] = min(mc[i], mc[i-1]);
        if(i<mc[i])continue;
        dp[i] = dp[i-mc[i]]+2;
    }

    int x;
    while(m--){
        cin >> x;
        if(x>N){
            int tms = (x-N + (mc[N]-1))/mc[N];
            ans+=tms*2;
            x-=tms*mc[N];
        }
        ans+=dp[x];
    }
    cout << ans;
    return 0;
}