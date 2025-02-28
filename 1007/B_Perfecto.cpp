#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N1 = 5e5+10;
const int N = N1*N1;

signed main(){
    int t;
    cin >> t;

    unordered_map<int,int> mp;
    for(int i=1; i*i<=N; i++){
        mp[i*i]=1;
    }

    while(t--){
        int n;
        cin >> n;
        if(n==1 || mp.count((n*(n+1))/2)){
            cout << -1 << endl;
            continue;
        }
        int arr[n+2];
        arr[1]=2;
        arr[2]=1;
        int sum=3;
        for(int i=3; i<=n; i++){
            sum+=i;
            if(mp.count(sum)){
                arr[i]=i+1;
                arr[i+1]=i;
                sum+=i+1;
                i++;
            }else{
                arr[i]=i;
            }
        }
        for(int i=1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}