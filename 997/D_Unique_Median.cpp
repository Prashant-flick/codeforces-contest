#include<bits/stdc++.h>
#define int long long 
#define inf 0X3f3f3f3f3f3f3f3f
using namespace std;
int T,n,a[100001],pre[100001];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int k=1;k<=10;k++){
			
			for(int i=1;i<=n;i++)pre[i+1]=pre[i]+(a[i]<=k?1:-1);
			unordered_map<int,int>mp;
			int p=1,sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==k)for(;p<=i;p++)mp[pre[p]]++;
				sum+=(a[i]<=k?1:-1),ans+=mp[sum];
			}
			cout << k << " " << ans << endl; 
		}
		cout << ans << endl;
		cout<<n*(n+1)/2-ans<<'\n';
	}
}