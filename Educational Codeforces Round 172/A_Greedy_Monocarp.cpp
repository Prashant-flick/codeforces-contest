#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        int sum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        int cnt=0;
        int i=0;
        while(i<n && cnt<k){
            cnt+=arr[i];
            i++;
        }
        if(cnt<k){
            cout << k-cnt << endl;
            continue;
        }
        if(cnt==k){
            cout << 0 << endl;
            continue;
        }
        cout << k-(cnt-arr[i-1]) << endl;
    }
}