#include<bits/stdc++.h>

using namespace std;

int main() {
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
        sort(arr, arr + n);
        int index = n/2 + n%2;
        index--;
        int ans=0;
        for(int i=index; i<n; i++)
        {
            if(arr[i]==arr[index]){
                ans++;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}