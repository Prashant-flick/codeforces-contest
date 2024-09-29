#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--){
		int x,y,z; cin>>x>>y>>z;
		int a=(x^z);
		if((x|a)-(y&a)==z) cout<<a<<'\n'; 
		else cout<<-1<<'\n';
	}
}
