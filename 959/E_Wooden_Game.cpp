#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            for(int j=0; j<arr[i]-1; j++){
                int temp;
                cin >> temp;
            }
        }

        int cnt[30]={0};
        for(int &a: arr){
            for(int i=0; i<30; i++){
                if((a&(1<<i))){
                    cnt[i]++;
                }
            }
        }

        int ans=0;
        for(int i=29; i>=0; i--){
            if(cnt[i]==1){
                ans+=(1<<i);
            }else if(cnt[i]>1){
                ans+=(1<<(i+1))-1;
                break;
            }
        }

        cout << ans << endl;

    }
    return 0;
}