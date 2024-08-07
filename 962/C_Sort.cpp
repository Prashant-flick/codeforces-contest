#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin>>t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s1;
        string s2;
        cin >> s1 >> s2;

        int mp[n][26]={0};
        for(int i=0; i<n; i++){
            mp[i][s1[i]-'a']++;
        }
        int mp2[n][26]={0};
        for(int i=0; i<n; i++){
            mp2[i][s2[i]-'a']++;
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<26; j++){
                mp[i][j]+=mp[i-1][j];
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<26; j++){
                mp2[i][j]+=mp2[i-1][j];
            }
        }

        while(q--){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            int size = (b-a+1);
            int cnt=0;
            int ans[26]={0};
            for(int j=0; j<26; j++){
                ans[j]=(mp[b][j]-(a>0 ? mp[a-1][j]:0));
            }
            for(int j=0; j<26; j++){
                ans[j]=abs(ans[j]-(mp2[b][j]-(a>0 ? mp2[a-1][j]:0)));
                cnt+=ans[j];
            }
            cout << cnt/2 << endl;
        }


    }
    return 0;
}