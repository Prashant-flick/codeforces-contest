#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> p;

const int N = 4e5+10;
int arr[N],brr[N],dist[N],pre[N];
int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            pre[i]=(i!=0?pre[i-1]:0)+arr[i];
        }
        for(int i=0; i<n; i++){
            dist[i]=1e18;
            cin >> brr[i];
            brr[i]--;
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            int v = brr[u];
            int weight = arr[u];
            if(dist[v] > dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push({dist[v], v});
            }
            int v1 = u-1;
            if(dist[v1] > dist[u]){
                dist[v1]=dist[u];
                pq.push({dist[v1], v1});
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(dist[i]!=1e18){
                ans=max(ans, pre[i]-dist[i]);
            }
        }
        cout << ans << endl;
    }
    
}