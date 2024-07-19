#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];

int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[62]={0};

        int last=0;
        int cnt=0;
        for(int i=0; i<63; i++){
            if(((1LL<<i)&n)==(1LL<<i)){
                last=max(last,i);
                arr[i]=1;
                cnt++;
            }
        }

        if(cnt==1){
            cout << 1 << endl;
            cout << (1LL<<last) << endl;
        }else{
            cout << cnt+1 << endl;
            cout << (n-(1LL<<last)) << " ";
            for(int j=1; j<=cnt; j++){
                int sum = 0;
                int i=62;
                int cnt=j;
                while(cnt){
                    if(arr[i]==1){
                        sum+=(1LL<<i);
                        cnt--;
                    }
                    i--;
                }
                int k=0;
                for(; i>=0; i--){
                    if(arr[i]==1){
                        if(k%2!=0){
                            sum+=(1LL<<i);
                        }
                        k++;
                    }
                }
                cout << sum << " ";
            }
            cout << endl;
        }


    }
    return 0;
}