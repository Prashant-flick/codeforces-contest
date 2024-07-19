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
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i-2; j<=i+2; j++){
                if(j>=0 && j<n && j!=i && arr[i]<=arr[j]){
                    ans = max(ans, arr[i]);
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}
