#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int i=0;
        int ans1=0;
        while(i<n){
            while(i<n && (arr[i]==0 || arr[i]>2)){
                if(arr[i]>2)ans1++;
                i++;
            }
            if(i<n && arr[i]<=2){
                int cnt1=1;
                i++;
                while(i<n && arr[i]!=0 && arr[i]<=2){
                    cnt1++;
                    i++;
                }
                if(i==n){
                    ans1+=cnt1/2 + cnt1%2;
                    continue;
                }
                if(i<n && arr[i]==0){
                    ans1 += (cnt1/2 + cnt1%2);
                    i++;
                    continue;
                }
                int cnt=0;
                while(i<n && arr[i]>2 && arr[i]<=4){
                    cnt++;
                    i++;
                }
                if(i==n){
                    ans1+=cnt1/2+cnt1%2;
                    ans1+=cnt;
                    continue;
                }
                if(i<n && arr[i]==0){
                    ans1+=cnt1/2+cnt1%2;
                    ans1+=cnt;
                    i++;
                    continue;
                }
                int cnt3=0;
                int j=i;
                while(j<n && arr[j]!=0 && arr[j]<=2){
                    cnt3++;
                    j++;
                }

                if(cnt!=0 && cnt%2==0){
                    if(cnt1%2==1 && cnt3%2==1){
                        cnt1--;
                        cnt3--;
                        ans1+=cnt1/2+cnt1%2;
                        ans1+=cnt+1;
                        ans1+=cnt3/2+cnt3%2;
                        i=j;
                    }else if(cnt1%2==1 && cnt3%2==0){
                        cnt1--;
                        ans1+=cnt1/2+cnt1%2;
                        ans1+=cnt+1;
                        cnt3-=2;
                        ans1+=cnt3/2+cnt3%2;
                        i=j-1;
                    }else if(cnt1%2==0 && cnt3%2==1){
                        ans1+=cnt1/2+cnt1%2;
                        ans1+=cnt;
                        cnt3--;
                        ans1+=cnt3/2+cnt3%2;
                        i=j-1;
                    }else{
                        ans1+=cnt1/2+cnt1%2;
                        ans1+=cnt3/2+cnt3%2;
                        ans1+=cnt;
                        i=j;
                    }
                }else{
                    ans1+=cnt1/2+cnt1%2;
                    ans1+=cnt;
                    if(j==n){
                        ans1+=cnt3/2+cnt3%2;
                        i=j;
                        continue;
                    }
                }
            }
        }
        cout << ans1 << endl;
    }
    
    return 0;
}