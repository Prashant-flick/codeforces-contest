#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++)
    {
        cin >> arr[i];
    }
    int ans[n];
    ans[0]=0;
    for (int i = 0; i < n-1; i++)
    {
        ans[i+1]=ans[i]^arr[i];
    }
    int temp=0;
    int st=1;
    int x = __builtin_clz(n);
    for (int i = 0; i < 32-x; i++)
    {
        int ones1=0;
        int ones2=0;
        for (int j=0; j < n; j++)
        {
            if(((j>>i)&1))ones2++;
            if(((ans[j]>>i)&1))ones1++;
        }
        // cout << ones1 << " " << ones2 << endl;
        if(ones1!=ones2)temp=temp^st^0LL;
        st*=2;
    }
    if(temp!=0){
        ans[0]=temp;
        for (int i = 0; i < n-1; i++)
        {
            ans[i+1]=ans[i]^arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}