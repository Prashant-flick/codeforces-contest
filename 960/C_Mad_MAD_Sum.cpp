#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        int ans=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            ans+=arr[i];
        }

        int brr[n]={0};
        unordered_map<int,int> mp;
        int maxi=0;
        mp[arr[0]]++;
        int sum=0;
        for(int i=1; i<n; i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>=2 && arr[i]>maxi){
                maxi=arr[i];
            }
            brr[i]=maxi;
            sum+=brr[i]+0LL;
        }

        ans+=sum+0LL;
        int i=1;
        while(i<n-1 && brr[i]!=brr[i+1]){
            sum=sum-brr[i]-0LL;
            brr[i]=0;
            i++;
        }
        if(i==n-1){
            sum=sum-brr[i]-0LL;
        }

        while(i<n){
            int cnt=1;
            while(i<n-1 && brr[i]==brr[i+1]){
                cnt++;
                i++;
            }
            if(cnt==1){
                sum-=(brr[i]-brr[i-1]);
                brr[i]=brr[i-1];
            }
            i++;
        }
        
        for(int j=n-1; j>=0; j--){
            if(brr[j]==0)break;
            sum=sum-brr[j]-0LL;
            ans=ans+sum+0LL;
        }
        cout << ans << endl;
    }
    
    return 0;
}