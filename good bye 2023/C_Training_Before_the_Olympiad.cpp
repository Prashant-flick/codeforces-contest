#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum=0,odd=0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum+=temp;
            if(temp%2!=0)odd++;
            if(i==0)cout << temp << " ";
            else{
                cout << sum - (odd/3) - (odd%3==1) << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}