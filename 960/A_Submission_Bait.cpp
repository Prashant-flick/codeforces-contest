#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        unordered_map<int,int> mp;
        int maxi2=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
            maxi2=max(maxi2,arr[i]);
        }
        stack<int> st;
        auto it=mp.begin();
        while(it!=mp.end()){
            st.push(it->second);
            it++;
        }

        int temp=0;
        bool flag=false;
        while(!st.empty()){
            temp+=st.top();
            st.pop();
            if(temp%2==1){
                flag=true;
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }


    }
    
    return 0;
}