#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    string s[n];
    int maxi=0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        maxi=max(maxi, (int)s[i].size());
    }
    unordered_map<int,int> mp[maxi+1];
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        for (int j = 0; j < s[i].size(); j++)
        {
            sum+=s[i][j]-'0';
        }
        mp[s[i].size()][sum]++;
    }

    int ans=0;
    for (int i = 0; i < n; i++)
    {
        int n = s[i].size();
        int sum=0;
        for (int j= 0; j < n ; j++)
        {
            sum+=s[i][j]-'0';
        }
        int sum2=0;
        for (int j= 0; j < n ; j++)
        {
            sum2+=s[i][j]-'0';
            if(j+1>n/2){
                ans+=mp[((j+1)-(n-(j+1)))][2*sum2-sum];
            }
        }
        sum2=0;
        for (int j=0; j < n ; j++)
        {
            sum2+=s[i][n-j-1]-'0';
            if(j+1>n/2){
                ans+=mp[((j+1)-(n-(j+1)))][2*sum2-sum];
            }
        }
        ans-=mp[n][sum];
    }
    
    cout << ans << endl;
    
    return 0;
}