#include<bits/stdc++.h>
using namespace std;

bool flag;
int maxi1,maxi2,maxi3,maxi4,maxi5,maxi6,maxi7,maxi8;

void findPath(unordered_map<int,vector<int>> &adj, int u, int v, int *vis, vector<int> &ans){
    if(flag)return;
    vis[u]=1;
    ans.push_back(u);
    for(int &v1: adj[u]){
        if(v1==v){
            vis[v]=1;
            ans.push_back(v);
            flag=true;
            return;
        }
        if(!vis[v1]){
            findPath(adj, v1, v, vis, ans);
        }
    }
    if(!flag){
        ans.pop_back();
    }
    return;
}

void solve(unordered_map<int,vector<int>> &adj, int u, int v3, int v2, int cnt, int *vis, int check){
    vis[u]=1;
    if(check==0){
        maxi1=max(maxi1, cnt);
    }else if(check==1){
        maxi2=max(maxi2, cnt);
    }
    for(int &v1: adj[u]){
        if(v1!=v3 && v1!=v2 && !vis[v1]){
            solve(adj, v1, v3, v2, cnt+1, vis, check);
        }
    }
}

void solve1(unordered_map<int,vector<int>> &adj, int u, int v3, int v2, int cnt, int *vis, int check, int *cnt1){
    vis[u]=1;
    cnt1[check]=max(cnt1[check], cnt);
    for(int &v1: adj[u]){
        if(v1!=v3 && v1!=v2 && !vis[v1]){
            solve1(adj, v1, v3, v2, cnt+1, vis, check, cnt1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n-1; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int u,v;
        cin >> u >> v;
        
        int vis[n+1]={0};
        vector<int> ans;
        flag=false;
        findPath(adj, 1, v, vis, ans);
        
        int size = ans.size();
        maxi1=maxi2=0;
        memset(vis, 0, sizeof vis);
        solve(adj, 1, ans[1], (-5), 0, vis, 0);
        memset(vis, 0, sizeof vis);
        solve(adj, u, ans[size-2], (-5), 0, vis, 1);

        int cnt1[size]={0};
        cnt1[0]=maxi1;
        cnt1[size-1]=maxi2;
        for(int i=1; i<size-1; i++){
            memset(vis, 0, sizeof vis);
            int a = ans[i+1];
            int b = ans[i-1];
            int c = ans[i];
            solve1(adj, c, a, b, 0, vis, i, cnt1);
        }

        int maxi0[size]={0};
        int maxi00[size]={0};
        maxi0[size-1]=cnt1[size-1];
        maxi00[size-1]=cnt1[size-1];
        int j=1;
        for(int i=size-2; i>=0; i--){
            maxi0[i]=max(maxi0[i+1], cnt1[i]+j);
            maxi00[i]=cnt1[i]+j;
            j++;
        }

        bool flag1=false;
        int maxii=INT_MIN;
        int i=0;
        int newm;
        for(; i<=(size-1)/2; i++){
            maxii=i+cnt1[i];
            if(maxii>maxi0[i+1]){
                flag1=true;
                break;
            }
            newm=maxi0[i+1];
        }

        if(flag1){
            cout << "Alice" << endl;
        }else{
            while(i<size-1 && newm!=maxi00[i]){
                maxii=i+cnt1[i];
                if(maxii>newm){
                    flag1=true;
                    break;
                }
                if(maxii<=maxi00[i])break;
                i++;
            }
            if(flag1){
                cout << "Alice" << endl;
            }else{
                cout << "Bob"  << endl;
            }
        }
    }
}