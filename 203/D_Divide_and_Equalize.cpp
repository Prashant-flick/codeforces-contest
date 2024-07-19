#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j*j<=arr[i]; j++)
            {
                while(arr[i]%j==0)
                {
                    mp[j]++;
                    arr[i]/=j;
                }
            }
            if(arr[i]!=1){
                mp[arr[i]]++;
            }
        }
        
        auto it=mp.begin();
        while(it!=mp.end()){
            if(it->second%n!=0){
                cout << "NO" << endl;
                break;
            }
            it++;
        }
        if(it==mp.end())cout << "YES" << endl;
        
    }
    
    return 0;
}