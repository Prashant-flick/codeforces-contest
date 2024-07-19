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
        cin >> arr[0];
        int num1 = arr[0];
        bool flag=true;
        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i]!=num1){
                flag=false;
            }
        }


        if(flag || n<=2){
            cout << -1 << endl;
            continue;
        }


        int ans=n-1;
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(arr[i]!=num1){
                ans = min(ans, cnt);
                cnt=0;
            }else{
                cnt++;
            }
        }
        ans = min(ans, cnt);
        
        cout << ans << endl;
    }
    

    return 0;
}