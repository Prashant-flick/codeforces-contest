#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300005],d[300005];
bool f[300005];
int l[300005],r[300005];
void test()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i]=1;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++)
		l[i]=i-1,r[i]=i+1;
	r[n]=0;
	queue<int> q;
	for(int i=1;i<=n;i++)
		q.push(i);
	for(int i=1;i<=n;i++)
	{
		vector<int> die;
		int cnt=q.size();
		for(int j=1;j<=cnt;j++)
		{
			int x=q.front();
			q.pop();
			if(f[x]&&a[l[x]]+a[r[x]]>d[x])
			{
				f[x]=0;
				die.push_back(x);
			}
		}
		cout<<die.size()<<" ";
		for(int d:die)
		{
			l[r[d]]=l[d];
			r[l[d]]=r[d];
			q.push(l[d]);
			q.push(r[d]);
		}
	} 
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		test(); 
}