#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        arr[1]=2;
        arr[2]=1;
        arr[3]=3;
        arr[4]=4;
        arr[5]=5;
        int ans=0;
        int currIdx = 3;
        for(int i=6; i<=n; i++){
            if(i%2==0){
                int maxi=0;
                for(int j=0; j<22; j++){
                    if(((1<<j)&(i))==(1<<j)){
                        maxi=j;
                    }
                }
                if((1<<maxi)==i){
                    arr[i]=i;
                    currIdx=i-1;
                    continue;
                }
                int temp = (1<<maxi);
                maxi--;
                arr[i]=i;
                swap(arr[i], arr[currIdx]);
                currIdx=i;
            }else{
                arr[i]=i;
            }
        }

        if(n%2!=0){
            cout << n << endl;
            for(int i=1; i<=n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            continue;
        }
        int i=0;
        for(; i<22; i++){
            if(((1<<i)&(n))==(1<<i)){
                ans=i;
            }
        }
        ans++;
        ans=(1<<ans);
        ans--;
        cout << ans << endl;
        for(int i=1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}