#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n,q,p;
        cin >> n >> q;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        string s;
        cin >> s;
        int left[n]={0};
        left[0]=arr[0];
        for(int i=1; i<n; i++){
            left[i]=max(left[i-1], arr[i]);
        }
        int right[n]={0};
        right[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            right[i]=min(right[i+1], arr[i]);
        }

        int cnt=0;
        for(int i=0; i<n-1; i++){
            if(s[i]=='L' && s[i+1]=='R' && left[i]>=right[i+1]){
                cnt++;
            }
        }

        while(q--){
            cin >> p;
            p--;
            if((s[p]=='L' && s[p+1]=='R' && left[p]>=right[p+1]) || (s[p]=='R' && s[p-1]=='L' && left[p-1]>=right[p])){
                cnt--;
            }
            s[p]=((s[p]=='L')?'R':'L');
            if((s[p]=='L' && s[p+1]=='R' && left[p]>=right[p+1]) || (s[p]=='R' && s[p-1]=='L' && left[p-1]>=right[p])){
                cnt++;
            }
            if(cnt==0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}