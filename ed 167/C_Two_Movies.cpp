#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<n; i++)cin >> brr[i];

        int r1=0;
        int r2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0; i<n; i++){
            if(arr[i]==1 && brr[i]==1){
                cnt1++;
            }else if(arr[i]==1){
                r1++;
            }else if(brr[i]==1){
                r2++;
            }else if(arr[i]==0 || brr[i]==0){
                continue;
            }else{
                cnt2++;
            }
        }

        if(r2>r1){
            int temp = r1;
            r1=r2;
            r2=temp;
        }

        int ans=0;
        if(r1==r2){
            if(cnt1+cnt2==1){
                if(cnt1==1){
                    ans = r1;
                }else{
                    ans = r1-1;
                }
            }
            else if((cnt1+cnt2)%2==0){
                r1+=cnt1/2;
                r1-=cnt2/2;
                ans = r1;
            }else{
                r1+=cnt1/2;
                r1-=cnt2/2;
                if(cnt2%2!=0){
                    ans = r1-1;
                }else{
                    ans = r1;
                }
            }
        }       
        else if(r1-r2<=cnt1){
            cnt1-=r1-r2;
            r2=r1;
            if(cnt1+cnt2==1){
                if(cnt1==1){
                    ans = r1;
                }else{
                    ans = r1-1;
                }
            }
            else if((cnt1+cnt2)%2==0){
                r1+=cnt1/2;
                r1-=cnt2/2;
                ans = r1;
            }else{
                r1+=cnt1/2;
                r1-=cnt2/2;
                if(cnt2%2!=0){
                    ans = r1-1;
                }else{
                    ans = r1;
                }
            }
        }else if(r1-r2<=cnt2){
            cnt2-=r1-r2;
            r1=r2;
            if(cnt1+cnt2==1){
                if(cnt1==1){
                    ans = r1;
                }else{
                    ans = r1-1;
                }
            }
            else if((cnt1+cnt2)%2==0){
                r1+=cnt1/2;
                r1-=cnt2/2;
                ans = r1;
            }else{
                r1+=cnt1/2;
                r1-=cnt2/2;
                if(cnt2%2!=0){
                    ans = r1-1;
                }else{
                    ans = r1;
                }
            }
        }else{
            r2+=cnt1;
            cnt1=0;
            if(r1-r2<=cnt2){
                cnt2-=r1-r2;
                r1=r2;
                if(cnt2==1){
                    ans=r1-1;
                }
                else if(cnt2%2==0){
                    r1-=cnt2/2;
                    ans=r1;
                }else{
                    r1-=cnt2/2;
                    ans = r1-1;
                }
            }else{
                r1-=cnt2;
                cnt2=0;
                ans = min(r1,r2);
            }
        }

        cout << ans << endl;
    }
}