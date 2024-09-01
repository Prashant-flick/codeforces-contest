#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        if(n%2==1){
            vector<vector<int>> left1(n/2+1, vector<int> (26,0));
            vector<vector<int>> left2(n/2+1, vector<int> (26,0));
            left1[0][s[0]-'a']++;
            left2[0][s[1]-'a']++;
            for(int i=2; i<n; i++){
                if(i%2==0){
                    for(int j=0; j<26; j++){
                        left1[i/2][j]=left1[i/2-1][j]+((s[i]-'a')==j?1:0);
                    }
                }else{
                    for(int j=0; j<26; j++){
                        left2[i/2][j]=left2[i/2-1][j]+((s[i]-'a')==j?1:0);
                    }
                }
            }
            vector<vector<int>> right1(n/2+1, vector<int> (26,0));
            vector<vector<int>> right2(n/2+1, vector<int> (26,0));
            right1[n/2][s[n-1]-'a']++;
            right2[n/2][s[n-2]-'a']++;
            for(int i=n-3; i>=0; i--){
                if(i%2==0){
                    for(int j=0; j<26; j++){
                        right1[i/2][j]=right1[i/2+1][j]+((s[i]-'a')==j?1:0);
                    }
                }else{
                    for(int j=0; j<26; j++){
                        right2[(i+1)/2][j]=right2[(i+1)/2+1][j]+((s[i]-'a')==j?1:0);
                    }
                }
            }
            
            int ans=INT_MAX;
            for(int i=0; i<n; i++){
                if(i==0){
                    int maxi1=INT_MIN;
                    int maxi2=INT_MIN;
                    for(int j=0; j<26; j++){
                        maxi1=max(maxi1, right1[(i+2)/2][j]);
                        maxi2=max(maxi2, right2[(i+2)/2][j]);
                    }
                    ans = min(ans, n-(maxi1+maxi2)-1);
                }else if(i==n-1){
                    int maxi1=INT_MIN;
                    int maxi2=INT_MIN;
                    for(int j=0; j<26; j++){
                        maxi1=max(maxi1, left1[(i-1)/2][j]);
                        maxi2=max(maxi2, left2[(i-1)/2][j]);
                    }
                    ans = min(ans, n-(maxi1+maxi2)-1);
                }else{
                    int maxi1=INT_MIN;
                    int maxi2=INT_MIN;
                    for(int j=0; j<26; j++){
                        if(i%2==0){
                            maxi1=max(maxi1, right1[(i+2)/2][j]+left2[(i-1)/2][j]);
                            maxi2=max(maxi2, right2[(i+2)/2][j]+left1[(i-1)/2][j]);
                        }else{
                            maxi1=max(maxi1, right1[(i+1)/2][j]+(i>1?left2[(i-2)/2][j]:0));
                            maxi2=max(maxi2, (i<n-2?right2[(i+3)/2][j]:0)+left1[(i-1)/2][j]);
                        }
                    }
                    ans = min(ans, n-(maxi1+maxi2)-1);
                }
            }
            cout << ans+1 << endl;
        }else{
            vector<int> cnt1(26,0);
            vector<int> cnt2(26,0);
            for(int i=0; i<n; i++){
                if(i%2==0){
                    cnt1[s[i]-'a']++;
                }else{
                    cnt2[s[i]-'a']++;
                }
            }
            int maxi1=INT_MIN;
            int maxi2=INT_MIN;
            for(int i=0; i<26; i++){
                maxi1=max(maxi1, cnt1[i]);
                maxi2=max(maxi2, cnt2[i]);
            }

            cout << n-(maxi1+maxi2) << endl;
        }
    }
}