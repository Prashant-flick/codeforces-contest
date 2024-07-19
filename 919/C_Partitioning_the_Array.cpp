#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int a,int b){
    if(a<b)swap(a,b);
    if(b==0 || b==a)return a;
    return GCD(b,a%b);
}

int32_t main(){
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

        int ans=1;
        for (int i = 1; i <n ; i++)
        {
            if(n%i==0){
                int totgcd=0;
                for (int j = 0; j < i; j++)
                {
                    int gcd = 0;
                    for (int k = j+i; k < n; k+=i)
                    {
                        gcd = GCD(gcd, abs(arr[j]-arr[k]));
                    }
                    totgcd = GCD(totgcd, gcd);
                }
                if(totgcd!=1)ans++;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}