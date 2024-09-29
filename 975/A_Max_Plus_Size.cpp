#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int sum1=0;
        int sum2=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i%2==0){
                sum1=max(sum1,arr[i]);
            }else{
                sum2=max(sum2,arr[i]);
            }
        }

        cout << max(sum1+(n/2+n%2), sum2+(n/2)) << endl;
    }
    
    
}