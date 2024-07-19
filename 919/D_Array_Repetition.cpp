#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ull __int128 
const ll maxn=1e6+7,mod=1e9+7;
ll n,m,t,a[maxn],q;
void solve(){
	cin>>n>>q;vector<ull>cp;map<ull,ll>mp;
	ull now=0;
	for(int i=1;i<=n;i++){
		ll opt,x;
		cin>>opt>>x;
		if(now>1e18)continue;
		if(opt==1){
			now++;
			mp[now]=x;
		}
		else{
			cp.push_back(now);
			now*=(x+1);
		}
	}
	while(q--){
		ll x;
		cin>>x;
		for(int i=cp.size()-1; i>=0 ;i--){
			if(mp.count(x)){
				break;
			}
			x%=(cp[i]);
			if(x==0){
				x=cp[i];
			}
		}
		cout<<mp[x]<<" ";
	}
	cout<<endl;
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}
}