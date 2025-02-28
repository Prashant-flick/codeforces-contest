#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+10;
int arr[N*2+5],pre[N*2+5];

int solve1(vector<pair<int,int>> &vec){
    int one=0,zero=0;
    int m = vec.size();
    for(int i=vec[m-1].first; i<=vec[m-1].second; i++){
        if(arr[i]==1){
            one++;
        }else{
            zero++;
        }
    }
    int l1 = vec[m-1].first,r1=vec[m-1].second;
    int felem=arr[l1],lelem=arr[r1];
    int pref=felem,prel=lelem;
    if(felem==0){
        felem=1;
    }else{
        if(l1%2==0){
            felem=0;
        }else{
            felem=1;
        }
    }
    if(lelem==0){
        lelem=1;
    }else{
        if(r1%2==0){
            lelem=0;
        }else{
            lelem=1;
        }
    }
    m--;
    while(m--){
        int newone = zero*2;
        int newzero = 0;
        if(pref && l1%2){
            newone+=2;
            one--;
        }
        if(one>0 && prel && r1%2){
            newone+=2;
            one--;
        }
        newzero+=((one+1)/2)*2;
        newone+=(one/2)*2;
        l1=l1*2;
        r1=r1*2+1;
        int l11=l1,r11=r1;
        if(vec[m].first==l1+1){
            if(felem){
                newone--;
            }else{
                newzero--;
            }
            l1++;
        }
        if(vec[m].second==r1-1){
            if(lelem){
                newone--;
            }else{
                newzero--;
            }
            r1--;
        }
        pref=felem,prel=lelem;
        if(felem==0){
            felem=1;
        }else{
            if(l1%2==0){
                felem=0;
            }else{
                felem=1;
            }
        }
        if(lelem==0){
            lelem=1;
        }else{
            if(r1%2==0){
                lelem=0;
            }else{
                lelem=1;
            }
        }
        one=newone,zero=newzero;
    }
    return one;
}

int solve2(vector<pair<int,int>> &vec){
    int one=0,zero=0,m=vec.size();
    for(int i=vec[m-1].first; i<=vec[m-1].second; i++){
        if(arr[i]==1){
            one++;
        }else{
            zero++;
        }
    }
    int l1 = vec[m-1].first,r1=vec[m-1].second;
    int felem=arr[l1],lelem=arr[r1];
    int pref=felem,prel=lelem;
    if(felem==0){
        felem=0;
    }else{
        if(l1%2==0){
            felem=1;
        }else{
            felem=0;
        }
    }
    if(lelem==0){
        lelem=0;
    }else{
        if(r1%2==0){
            lelem=1;
        }else{
            lelem=0;
        }
    }
    m--;
    while(m--){
        int newone = 0;
        int newzero = zero*2;
        if(pref && l1%2){
            newzero+=2;
            one--;
        }
        if(one>0 && prel && r1%2){
            newzero+=2;
            one--;
        }
        newone+=((one+1)/2)*2;
        newzero+=(one/2)*2;
        l1=l1*2;
        r1=r1*2+1;
        if(vec[m].first==l1+1){
            if(felem){
                newone--;
            }else{
                newzero--;
            }
            l1++;
        }
        if(vec[m].second==r1-1){
            if(lelem){
                newone--;
            }else{
                newzero--;
            }
            r1--;
        }
        pref=felem,prel=lelem;
        if(felem==0){
            felem=0;
        }else{
            if(l1%2==0){
                felem=1;
            }else{
                felem=0;
            }
        }
        if(lelem==0){
            lelem=0;
        }else{
            if(r1%2==0){
                lelem=1;
            }else{
                lelem=0;
            }
        }
        one=newone,zero=newzero;
    }
    return one;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,l,r,f;
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
        f=arr[R];
        if(r<=R){
            int sum=0;
            for(int i=l; i<=r; i++){
                sum+=arr[i];
            }
            cout << sum << endl;
            continue;
        }
        pre[0]=0;
        for(int i=1; i<=R; i++){
            pre[i]=pre[i-1]+arr[i];
        }
        int ans=0;
        if(l<=R){
            ans+=pre[R]-pre[l-1];
            l=R+1;
        }
        while(r>R){
            int r1=r;
            vector<pair<int,int>> vec;
            vec.push_back({l,r});
            while(l>L){
                l/=2;
                if(l<L){
                    l*=2;
                    break;
                }
                r/=2;
                vec.push_back({l,r});
            }
            int m = vec.size();
            if(vec[m-1].second>R){
                int idx = R;
                vec[m-1].second=idx;
                l = idx+1;
                for(int i=m-2; i>=0; i--){
                    idx*=2;
                    idx++;
                    vec[i].second=idx;
                    l=idx+1;
                }
            }
            if(f){
                int res1 = solve1(vec);
                ans += res1;
            }else{
                int res1 = solve2(vec);
                ans += res1;
            }
            if(r>R){
                r=r1;
            }
        }
        cout << ans << endl;
    }
}