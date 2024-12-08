#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(n<64 && (1LL<<(n-1))<k){
            cout << -1 << endl;
        }else{
            int arr[n];
            arr[n-1]=1;
            int p=0;
            int i=n-1;
            for(i=n-2; i>=0 && p<62; i--){
                arr[i]=arr[i]*2LL;
                p++;
            }
            vector<int> ans(n);
            int temp=(1LL<<p);
            int res=i+2;
            int i1=i+1;
            while(i>=0){
                ans[i]=i+1;
                i--;
            }        
            int j=n-1;
            while(temp>0){
                temp=temp/2LL;
                if(k>temp){
                    k=k-temp-0LL;
                    ans[j]=res;
                    res++;
                    j--;
                }else{
                    ans[i1]=res;
                    res++;
                    i1++;
                }
            }
            for(int i=0; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}