// #include<bits/stdc++.h>
// using namespace std;

// #define int long long

// signed main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n >> k;
//         int arr[n],brr[n];
//         for(int i=0; i<n; i++)cin >> arr[i];
//         for(int i=0; i<n; i++)cin >> brr[i];
//         int l=1,r=2e9+10;
//         int mid=(l+r)/2;
//         int ans=1;
//         while(l<=r){
//             mid = (l+r)/2;
//             int k1 = k;
//             int res=0;
//             bool flag = true;
//             for(int i=0; i<n; i++){
//                 if(mid<=arr[i]){
//                     res+=mid;
//                 }else if(mid<=brr[i]){
//                     res+=mid;
//                     k1--;
//                     if(k1<0){
//                         flag=false;
//                         break;
//                     }
//                 }
//             }
//             if(flag && res>=ans){
//                 cout << mid << endl;
//                 l=mid+1;
//                 ans=max(ans,res);
//             }else{
//                 r=mid-1;
//             }
//         }

//         cout << ans << endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+5;
int T,n,k,a,b,d;ll c,ans;
map<int,pair<int,int>>mp;
int main(){
	scanf("%d",&T);while(T--){
		scanf("%d%d",&n,&k);c=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			mp[a].first++;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b);
			mp[b].second++;
		}
		for(pair<int,pair<int,int>>p:mp){
			if(d<=k)ans=max(ans,c*p.first);
			c-=p.second.second;
			d+=p.second.first-p.second.second;
		}
		printf("%lld\n",ans);
		ans=d=0;mp.clear();
	}
	return 0;
}