#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353

int n;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        int ans=1;
        int i=0;
        int prev=-1;
        int cnt1=0;
        int l=0;
        int pcnt=0;
        bool flag=true;
        bool flag1=(arr[0]==0?true:false);
        while(i<n){
            if(arr[i]-prev!=1 && arr[i]-prev!=0){
                while(i<n && arr[i]-prev!=1 && arr[i]-prev!=0){
                    prev=arr[i];
                    if(l==1){
                        if(arr[i]!=cnt1){
                            ans=0;
                            flag=false;
                            break;
                        }
                        l=0;
                    }else{
                        cnt1++;
                        l=1;
                    }
                    i++;
                }
                if(!flag)break;
            }else if(prev==arr[i]){
                if(l==1){
                    if(arr[i]!=cnt1){
                        ans=0;
                        break;
                    }
                    l=0;
                    int cnt=1;
                    while(i<n-1 && arr[i]==arr[i+1]){
                        i++;
                        cnt++;
                    }
                    i++;
                    pcnt=cnt;
                    cnt1++;
                }else{
                    int cnt=2;
                    while(i<n-1 && arr[i]==arr[i+1]){
                        i++;
                        cnt++;
                    }
                    i++;
                    pcnt=cnt;
                    cnt1++;
                }
            }else{
                if(l==1){
                    if(arr[i]!=cnt1){
                        ans=0;
                        break;
                    }
                    l=0;
                    prev=arr[i];
                    int cnt=0;
                    while(i<n-1 && arr[i]==arr[i+1]){
                        cnt++;
                        i++;
                    }

                    if(i==n-1){
                        if(cnt>=1){
                            ans=(ans*2)%MOD;
                        }
                    }
                    pcnt=cnt;
                    i++;
                    cnt1++;
                }else{
                    int num = arr[i];
                    int cnt=1+flag1;
                    prev=arr[i];
                    while(i<n-1 && arr[i]==arr[i+1]){
                        cnt++;
                        i++;
                    }
                    if(i==n-1 && flag1){
                        ans=2;
                        break;
                    }
                    if(i==n-1){
                        if(pcnt>=3){
                            if(cnt==2){
                                ans=(ans*2+1)%MOD;
                            }else if(cnt==1){
                                ans=(ans*2)%MOD;
                            }else{
                                ans=(ans*4)%MOD;
                            }
                        }else if(pcnt==1){
                            if(cnt==1){
                                ans = (ans+(ans==1?0:1))%MOD;
                            }else if(cnt==2){
                                ans = (ans+(ans==1?1:2))%MOD;
                            }else if(cnt>2){
                                ans = (ans+(ans==1?0:1))%MOD;
                                ans = (ans*2+1)%MOD;
                            }
                        }else if(pcnt==2){
                            if(cnt==2){
                                ans = (ans+(ans==1?2:3))%MOD;
                            }else if(cnt==1){
                                ans = (ans+(ans==1?0:1))%MOD;
                            }else{
                                ans = (ans+(ans==1?1:2))%MOD;
                                ans=(ans*2+1)%MOD;
                            }
                        }
                    }else if(pcnt>=2){
                        if(cnt>=2){
                            ans=(ans*2)%MOD;
                        }
                    }
                    if(cnt==1 && cnt1!=num){
                        l=1;
                        cnt1++;
                    }else if(cnt==1){
                        l=0;
                    }else{
                        cnt1++;
                    }
                    pcnt=cnt;
                    i++;
                }
            }
            flag1=false;
        }
        cout << ans << endl;
    }
}