#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    vector<vector<string>> vec(100);
    vec[3].push_back("169");
    vec[3].push_back("961");
    vec[3].push_back("196");
    for (int i = 5; i <= 100; i+=2){

        string p = vec[i-2][0];
        string q = vec[i-2][1];
        p.insert(1,"0");
        p.insert(i-2,"0");
        q.insert(1,"0");
        q.insert(i-2,"0");
        vec[i].push_back(p);
        vec[i].push_back(q);

        int j=0;
        while(j<i-2){
            vec[i].push_back(vec[i-2][j]+"00");
            j++;
        }
        
    }

    while (t--)
    {
        int n;
        cin >> n;
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cout << (vec[n][i]) << endl;   
        }
    }
    
    return 0;
}