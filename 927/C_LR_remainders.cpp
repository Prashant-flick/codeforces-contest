#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;

        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        string s;
        cin >> s;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            if(s[i]=='L'){
                arr[i]=dq.front();
                dq.pop_front();
            }else{
                arr[i]=dq.back();
                dq.pop_back();
            }
        }
        reverse(arr.begin(), arr.end());

        vector<int> ans(n);
        int res=1;
        for(int i=0; i<n; i++){
            res*=arr[i];
            res%=m;
            ans[i]=res;
        }

        reverse(ans.begin(), ans.end());
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }    
        
        cout << endl;
    }
    return 0;
}