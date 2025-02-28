#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+10;
int arr[N*2];

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n >> l >> r;
        for(int i=1; i<=n; i++)cin >> arr[i];
        int cnt=0;
        for(int i=1; i<=n/2; i++){
            cnt^=arr[i];
        }
        if(n%2==0){
            arr[++n]=cnt;
        }
        for(int i=n/2+1; i<=n; i++){
            cnt^=arr[i];
            arr[i*2]=cnt;
            arr[i*2+1]=cnt;
        }
        int L=n+1,R=n*2+1;
        if(l<=R){
            cout << arr[l] << endl;
            continue;
        }
        vector<int> vec;
        vec.push_back(l);
        while(l>R){
            l/=2;
            vec.push_back(l);
        }
        if(arr[R]){
            int m = vec.size();
            int res=arr[vec[m-1]];
            for(int i=m-2; i>=0; i--){
                if(res==0){
                    res=1;
                }else{
                    if(vec[i+1]%2==0){
                        res=0;
                    }else{
                        res=1;
                    }
                }
            }
            cout << res << endl;
        }else{
            int m = vec.size();
            int res=arr[vec[m-1]];
            for(int i=m-2; i>=0; i--){
                if(res==0){
                    res=0;
                }else{
                    if(vec[i+1]%2==0){
                        res=1;
                    }else{
                        res=0;
                    }
                }
            }
            cout << res << endl;
        }
    }
}