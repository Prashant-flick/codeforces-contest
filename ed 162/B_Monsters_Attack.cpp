#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n],brr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            // cout << arr[i] << endl;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> brr[i];
            mp[brr[i]]=arr[i];
            // cout << brr[i] << endl;
            if(brr[i] > maxi){
                maxi = brr[i];
            }
            if(brr[i]<mini){
                mini = brr[i];
            }
        }

        // cout << mini << " " << maxi << endl;

        for(int i=mini; i<=maxi; i++){
            if(mp.find(i) == mp.end()){
                mp[i]=0;
            } 
        }

        int i=-1,j=1;
        int carry=0;
        bool flag=true;
        while(i>=mini || j<=maxi){
            // cout << i << " " << j << endl;
            // cout << mp[i] << " " << mp[j] << " "<< carry << endl;
            int temp=(i>=mini?mp[i]:0)+(j<=maxi?mp[j]:0)-carry;
            // cout << temp << endl;
            if(temp<=k){
                carry=k-temp;
            }else{
                flag=false;
                break;
            }
            i--;
            j++;
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    return 0;
}