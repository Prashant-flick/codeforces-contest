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
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        int i=0;
        vector<int> vec;
        while (i<n-1)
        {
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                i++;
                while(i<n && arr[i]<temp){
                    vec.push_back(temp-arr[i]);
                    i++;
                }
            }else{
                i++;
            }
        }
        
        sort(vec.begin(), vec.end());
        int ans = 0;
        int m = vec.size();
        for(i=0; i<m; i++){
            if(i==0){
                ans+=(vec[i]*(m+1-i));
            }else{
                ans+= ((vec[i]-vec[i-1])*(m+1-i));
            }
        }
        cout << ans << endl;
    }
    
}