#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        int p = x-y+1;
        int k=-1;
        int i=y-1;
        int arr[n+1]={0};
        while(i>0){
            arr[i]=k;
            if(k==-1){
                k=1;
            }else{
                k=-1;
            }
            i--;
        }
        i=y;
        while(i<=x){
            arr[i]=1;
            i++;
        }
        k=-1;
        while(i<=n){
            arr[i]=k;
            if(k==-1){
                k=1;
            }else{
                k=-1;
            }
            i++;
        }

        for(int i=1; i<=n; i++){
            cout << arr[i] << " ";
        }

        cout << endl;
        
    }
    
    return 0;
}