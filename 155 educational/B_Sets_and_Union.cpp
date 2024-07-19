#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<unordered_map<int,int>> sets(n);
        unordered_map<int,int> store;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int p;
                cin >> p;
                sets[i][p]++;
                store[p]++;
            }
        }

        int ans = 0;
        int size = store.size();
        // cout << size << endl;
        auto it = store.begin();
        for(int i=0; i<store.size(); i++){
            unordered_map<int,int> tempstore = store;
            int p = it->first;
            int ans1 = size;
            for(int j=0; j<n; j++){
                if(sets[j].find(p)!=sets[j].end()){
                    auto it2 = sets[j].begin();
                    for(int k=0; k<sets[j].size(); k++){
                        tempstore[it2->first] = (tempstore[it2->first]-(it2->second));
                        if(tempstore[it2->first]==0){
                            ans1--;
                        }
                        it2++;
                    }
                }
            }
            if(ans1!=size){
                ans = max(ans1, ans);
            }
            it++;
        } 

        cout << ans << endl;
    }

    return 0;
}
