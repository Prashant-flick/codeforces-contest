#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, vector<pair<int,int>>> mp;
        vector<int> arr(2*n);
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            int a,b;
            cin >> a >> b;
            vec.push_back({a,b});
            arr[2*i]=a;
            arr[2*i+1]=b;
        }
        sort(arr.begin(), arr.end());
        for(auto it: vec){
            int a = it.first;
            int b = it.second;
            int idxa = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            int idxb = lower_bound(arr.begin(), arr.end(), b) - arr.begin();
            int c1 = ((2*n)-(idxa+1));
            int c2 = ((2*n)-(idxb+1));
            int c = c1+c2;
            mp[c].push_back({a,b});
        }

        int i=(2*n)-1;
        for(auto it: mp){
            for(pair<int,int> &p: it.second){
                arr[i-1]=p.first;
                arr[i]=p.second;
                i-=2;
            }
        }

        for(int i=0; i<2*n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
}