#include<bits/stdc++.h>
using namespace std;

#define int long long

bool solve(){
	int n,m,temp;
	cin >> n >> m;
	priority_queue<int> p,q;
	for(int i=0; i<n; i++){cin>>temp;p.push(temp);}
	for(int i=0; i<m; i++){cin>>temp;q.push(temp);}
	while(!p.empty() && !q.empty()){
		if(p.top()>q.top() || p.size()<q.size())return 0;
		if(p.top()==q.top()){p.pop();q.pop();continue;}
		int a = q.top();
		q.pop();
		q.push(a>>1);q.push(((a+1)>>1));
	}
	return (p.empty()&&q.empty());
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		cout << (solve()?"Yes":"No") << endl;	
	}
}