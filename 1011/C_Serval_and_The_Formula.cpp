#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        vector<pair<int,int>> vec(42,{0,0});
        for(int i=0; i<42; i++){
            if(((1LL<<i)&x)){
                vec[i].first=1;
            }
            if(((1LL<<i)&y)){
                vec[i].second=1;
            }
        }

        long long ans=0;
        int i=0,prev=0,prev1=0;
        while(i<40){
            if(vec[i].first==vec[i].second && vec[i].first==1){
                int cnt1=0,cnt2=0;
                int j=i;
                while(j<40 && vec[j].first){
                    cnt1++;
                    j++;
                }
                j=i;
                while(j<40 && vec[j].second){
                    cnt2++;
                    j++;
                }
                if(cnt1>cnt2){
                    ans+=(1LL<<i);
                    j=i;
                    while(j<40 && vec[j].first){
                        vec[j].first=0;
                        j++;
                    }
                    vec[j].first=1;
                    j=i;
                    while(j<40 && vec[j].second){
                        vec[j].second=0;
                        j++;
                    }
                    vec[j].second=1;
                }else if(cnt2>cnt1){
                    ans+=(1LL<<i);
                    j=i;
                    while(j<40 && vec[j].first){
                        vec[j].first=0;
                        j++;
                    }
                    vec[j].first=1;
                    j=i;
                    while(j<40 && vec[j].second){
                        vec[j].second=0;
                        j++;
                    }
                    vec[j].second=1;
                }else{
                    cnt1=0,cnt2=0;
                    j=i;
                    while(j>=0 && vec[j].first){
                        j--;
                        cnt1++;
                    }
                    j=i;
                    while(j>=0 && vec[j].second){
                        j--;
                        cnt2++;
                    }
                    if(cnt1==cnt2){
                        if(!prev){
                            j=i-cnt1+1;
                            ans+=(1LL<<j);
                            while(j<40 && vec[j].first && vec[j].second){
                                vec[j].first=0;
                                vec[j].second=0;
                                j++;
                            }
                            vec[j].first=1;
                            vec[j].second=1;
                        }else{
                            if(prev==1){
                                j=prev1;
                                while(j<i && vec[j].first){
                                    ans+=(1LL<<j);
                                    vec[j].first=0;
                                    vec[j+1].first=1;
                                    j++;
                                }
                                while(j<40 && vec[j].first){
                                    vec[j].first=0;
                                    j++;
                                }
                                vec[j].first=1;
                            }else{
                                j=prev1;
                                while(j<i && vec[j].second){
                                    ans+=(1LL<<j);
                                    vec[j].second=0;
                                    vec[j+1].second=1;
                                    j++;
                                }
                                while(j<40 && vec[j].second){
                                    vec[j].second=0;
                                    j++;
                                }
                                vec[j].second=1;
                            }
                        }
                    }else if(cnt1>cnt2){
                        j=i-cnt1+1;
                        ans+=(1LL<<j);
                        while(j<40 && vec[j].first){
                            vec[j].first=0;
                            j++;
                        }
                        vec[j].first=1;
                    }else if(cnt2>cnt1){
                        j=i-cnt2+1;
                        ans+=(1LL<<j);
                        while(j<40 && vec[j].second){
                            vec[j].second=0;
                            j++;
                        }
                        vec[j].second=1;
                    }
                }
                prev=0;
                i++;
            }else{
                if(vec[i].first){
                    prev=1;
                    prev1=i;
                }else if(vec[i].second){
                    prev=2;
                    prev1=i;
                }
                i++;
            }
        }
        int flag=1;
        for(int i=0; i<42; i++){
            if(vec[i].first==vec[i].second && vec[i].first==1){
                flag=0;
                break;
            }
        }
        if(flag){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }
    }
}