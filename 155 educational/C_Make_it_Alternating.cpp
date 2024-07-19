#include <bits/stdc++.h>
using namespace std;

long long fact(int n){
    long long ans = 1;
    while(n>1){
        ans = ((ans%998244353)*(n%998244353))%998244353;
        n--;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long n = s.size();
        if(n==1){
            cout << 0 << " " << 1 << endl;
        }else{
            long long cnt=0;
            long long cnt2=0;
            vector<long long> store;
            long long i=1;
            while(i < n)
            {
                if(s[i-1]==s[i]){
                    cnt++;
                    cnt2++;
                    i++;
                }else{
                    store.push_back(cnt2);
                    cnt2=0;
                    i++;
                }
            }
            if(cnt2!=0){
                store.push_back(cnt2);
            }
            long long ans = 1;
            i=0;
            for(i=0; i<store.size(); i++){
                ans = ((ans%998244353)*((store[i]+1)%998244353))%998244353;
            }

            ans = ((ans%998244353)*(fact(cnt)%998244353))%998244353;

            cout << cnt << " " << ans << endl;
        }
    }
    
    return 0;
}