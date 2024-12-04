#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
        }

        int sum=0;
        int sum1=0;
        int ans=0;
        for(auto it: mp){
            if(it.second==1){
                sum1++;
            }else{
                sum++;
            }
        }

        if(sum1%2==0){
            ans+=sum1;
            ans+=sum;
        }else{
            ans+=(sum1+1)/2;
            ans*=2;
            ans+=sum;
        }
        cout << ans << endl;
    }
}