#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multimap<int, pair<int,int>> mp;
        for (int i = 0; i < n; i++)
        {
            int a,b;
            cin >> a >> b;
            mp.insert({(b-a), {a,b}});
        }
        
        auto it = mp.begin();
        int ans=0;
        while (it!=mp.end())
        {
            int a,b;
            // cout << it->second.first << endl; 
            a=it->second.first;
            b=it->second.second;
            auto it1=it;
            it1++;
            while (it1!=mp.end())
            {
                int c,d;
                c=it1->second.first;
                d=it1->second.second;
                if(a>c && b<d)ans++;
                it1++;
            }
            it++;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}