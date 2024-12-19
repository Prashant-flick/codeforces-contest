#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        string p="";
        int i=0;
        while(i<n && s[i]=='1'){
            i++;
        }
        int j=i;
        int k=n-j;
        string p1="";
        while(i<n){
            if(s[i]=='1'){
                p+='0';
                p1+='1';
            }else{
                p+='1';
                p1+='0';
            }
            i++;
        }
        if(j==n){
            cout << 1 << " " << 1 << " " << 1 << " " << n << endl;
        }else{
            j--;
            int x=j;
            int cnt=0;
            int l=1;
            int r=l+k-1;
            vector<string> vec;
            while(j>=0){
                p1.pop_back();
                p1 = s[j] + p1;
                vec.push_back(p1);
                j--;
            }
            int m = vec.size();
            vector<int> vis(m,1);
            for(int i=0; i<k; i++){
                int cnt=0;
                for(int j=0; j<m; j++){
                    if(vec[j][i]==p[i]){
                        if(vis[j]==1){
                            cnt++;
                        }
                    }else{
                        vis[j]=-1;
                    }
                }
                if(cnt==1){
                    break;
                }else if(cnt==0){
                    for(int j=0; j<m; j++){
                        if(vis[j]==-1){
                            vis[j]=1;
                        }
                    }
                }else{
                    for(int j=0; j<m; j++){
                        if(vis[j]==-1){
                            vis[j]=0;
                        }
                    }
                }
            }
            for(int j=0; j<m; j++){
                // cout << vis[j] << endl;
                // cout << vec[j] << endl;
                if(vis[j]==1){
                    l=x-j+1;
                    r=l+k-1;
                    break;
                }
            }
            cout << l << " " << r << " " << 1 << " " << n << endl;
        }
    }
}