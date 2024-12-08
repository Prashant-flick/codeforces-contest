#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            vec[i]=s[i]-'0';
        }
        
        for(int i=0; i<n; i++){
            bool flag=true;
            int j=0;
            while(j<n-1){
                if(vec[j]<vec[j+1]-1){
                    vec[j+1]--;
                    swap(vec[j], vec[j+1]);
                    flag=false;
                }
                j++;
            }
            if(flag){
                break;
            }
        }

        for(int i=0; i<n; i++){
            cout << vec[i];
        }
        cout << endl;
    }
}