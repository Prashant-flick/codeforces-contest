#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++)
        {
            int x,y;
            cin >> x >> y;
            pq.push({x, 0 ,y});
            pq.push({y, 1 ,x});
        }

        // cout << pq.top()[0] << endl;
        // cout << pq.top()[1] << endl;
        // cout << pq.top()[2] << endl;

        int ans=0;
        ordered_set st;
        while (!pq.empty())
        {
            int x = pq.top()[0];
            int y = pq.top()[1];
            int z = pq.top()[2];
            pq.pop();
            if(y==0){
                st.insert(x);
            }else{
                // cout << (st.find(z)) << endl;
                cout << z << endl;
                st.erase(z);
                cout << st.order_of_key(z) << endl; 
                ans+=st.order_of_key(z);
            }
        }
        cout << ans << endl;
        
    }
    
    return 0;
}