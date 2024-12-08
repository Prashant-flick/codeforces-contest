#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int cnt[4]={0};
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=s[i]-'0';
            if(s[i]-'0'==2){
                cnt[2]++;
            }
            else if(s[i]-'0'==3){
                cnt[3]++;
            }
        }
        if(sum%9==0){
            cout << "YES" << endl;
        }else{
            int temp = (9-sum%9);
            if(temp%2==0 && temp/2<=cnt[2]){
                cout << "YES" << endl;
            }else if(temp==6 && cnt[3]>=1){
                cout << "YES" << endl;
            }else if(temp==8 && (cnt[3]>=1 && cnt[2]>=1)){
                cout << "YES" << endl;
            }else if(temp==3 && (cnt[3]>=2 || (cnt[3]>=1 && cnt[2]>=3) || (cnt[2]>=6))){
                cout << "YES" << endl;
            }else if(temp==5 && (cnt[2]>=7 || (cnt[3]>=2 && cnt[2]>=1) || (cnt[3]>=1 && cnt[2]>=4))){
                cout << "YES" << endl;
            }else if(temp==7 && ((cnt[3]>=2 && cnt[2]>=2) || (cnt[3]>=1 && cnt[2]>=5) || (cnt[2]>=8))){
                cout << "YES" << endl;
            }else if(temp==1 && (cnt[2]>=5 || (cnt[3]>=1 && cnt[2]>=2))){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}