#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int arr[n];
        cin >> arr[0];
        int pre[n];
        pre[0]=arr[0];
        for(int i=1; i<n; i++){
            cin >> arr[i];
            pre[i]=pre[i-1]+arr[i];
        }
        while (q--)
        {
            int l,r;
            cin >> l >> r;
            
            if((l-1)/n==(r-1)/n){
                int temp1 = (l-1)/n;
                int temp2 = (l-1)%n;
                int s = (temp1+temp2)%n;
                int temp3 = (r-1)/n;
                int temp4 = (r-1)%n;
                int e = (temp3+temp4)%n;
                int ans=0;
                if(s<=e){
                    if(s==0){
                        ans=pre[e];
                    }else{
                        ans=pre[e]-pre[s-1];
                    }
                }else{
                    ans = pre[n-1]-pre[s-1];
                    ans+=pre[e];
                }
                cout << ans << endl;
            }else{
                int temp1 = (l-1)/n;
                int temp2 = (l-1)%n;
                int s = (temp1+temp2)%n;
                int len = n-temp2;
                int sum=0;
                if(s+len<n){
                    if(s==0){
                        sum=pre[s+len-1];
                    }else{
                        sum=pre[s+len-1]-pre[s-1];    
                    }
                }else{
                    if(s==0){
                        sum=pre[n-1];
                    }else{
                        sum=pre[n-1]-pre[s-1];
                    }
                    len-=(n-s);
                    if(len>0){
                        sum+=pre[len-1];
                    }
                }
                int temp3 = (r-1)/n;
                int temp4 = (r-1)%n;
                int e = (temp3+temp4+1)%n;
                len = n-(temp4+1);
                int sum2=0;
                if(e+len<n){
                    if(e==0){
                        sum2=pre[e+len-1];
                    }else{
                        sum2=pre[e+len-1]-pre[e-1];
                    }
                }else{
                    if(e==0){
                        sum2=pre[n-1];
                    }else{
                        sum2=pre[n-1]-pre[e-1];
                    }
                    len-=(n-e);
                    if(len>0){
                        sum2+=pre[len-1];
                    }
                }
                sum2=pre[n-1]-sum2;

                int sum3 = (temp3-(temp1+1))*1LL*pre[n-1];
                cout << sum+0LL+sum2+sum3 << endl;
            }
            

        }
        
    }
}