#include<bits/stdc++.h>

using namespace std;

#define int long long

int findCost(vector<int> v,int d)
{
    
    int n=v.size();
    if(n-2<=d)
    {
        return 2;
    }
    int dp[n];
    dp[n-1]=1;
    dp[0]=1;
    for(int i=0;i<d+1;i++)
    {
        if(n-1-i-1>=1)
        {
            dp[n-i-2]=v[n-i-2]+1;
        }
    }
    int l=n-d-2;
    int r=n-2;
    multiset<int> costs;
    for(int i=l;i<=r;i++)
    {
        costs.insert(dp[i]);
    }
    for(int i=l-1;i>=1;i--)
    {
        dp[i]=v[i]+1+(*costs.begin());
        auto itr=costs.find(dp[r]);
        costs.erase(itr);
        costs.insert(dp[i]);
        r--;
    }
    int ans=LLONG_MAX;
    for(int i=1;i<=d+1;i++)
    {
        ans=min(ans,2+dp[i]);
    }
    return ans;

    
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,d,k;
        cin>>n>>m>>k>>d;
        vector<int> costs;
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m);
            for(int j=0;j<m;j++)
            {
                cin>>temp[j];
            }
            int cost=findCost(temp,d);
            costs.push_back(cost);
        }
        // vector<int> cum;
        // cum.push_back(costs[0]);
        // for(int i=1;i<n;i++)
        // {
        //     cum.push_back(cum.back()+costs[i]);
        // }
        // int ans=LLONG_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     int l=i;
        //     int r=i+k-1;
        //     if(r<=n-1)
        //     {
        //         if(l==0)
        //         {
        //             ans=min(ans,cum[r]);
        //         }
        //         else
        //         {
        //             ans=min(ans,cum[r]-cum[l-1]);
        //         }
        //     }
        // }
        int ans=0;
        sort(costs.begin(), costs.end());
        for(int i=0; i<k; i++){
            ans+=costs[i];
        }

        cout<<ans<<endl;

    }
}