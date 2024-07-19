#include<bits/stdc++.h>
using namespace std;

int n,k;

bool solve(string s, int i){
    int cnt1=0;
    int cnt0=0;
    bool flag=true;
    for(int j=i+1;j<n;j++){
        if(s[j]=='1'){
            if(cnt0!=k && cnt0!=0){
                flag=false;
                break;
            }
            cnt0=0;
            cnt1++;
        }else{
            if(cnt1!=k && cnt1!=0){
                flag=false;
                break;
            }
            cnt1=0;
            cnt0++;
        }
    }
    if(!flag){
        return flag;
    }

    // cout << "here3 " << i << endl;
    for(; i>=0; i--){
        if(s[i]=='1'){
            if(cnt0!=k && cnt0!=0){
                flag=false;
                break;
            }
            cnt0=0;
            cnt1++;
        }else{
            if(cnt1!=k && cnt1!=0){
                flag=false;
                break;
            }
            cnt1=0;
            cnt0++;
        }
    }

    // cout << "here4 " << cnt1 << " "  << cnt0 << endl;

    if(cnt1!=k && cnt0!=k){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt1=0;
        int cnt0=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1')cnt1++;
            else cnt0++;
        }

        if(cnt1%k!=0 || cnt0%k!=0 || (abs(cnt1-cnt0)!=0 && abs(cnt1-cnt0)!=k)){
            cout << -1 << endl;
            continue;
        }
        // cout << "here1" << endl;

        cnt1=0;
        cnt0=0;
        int i=0;
        for(; i<n; i++){
            if(s[i]=='1'){
                if(cnt0!=k && cnt0!=0){
                    cnt1=0;
                    cnt1=1;
                    break;
                }
                
                cnt0=0;
                cnt1++;
                if(cnt1>k){
                    cnt1=1;
                    cnt0=0;
                    break;
                }
            }else{
                if(cnt1!=k && cnt1!=0){
                    cnt1=1;
                    cnt0=0;
                    break;
                }
                
                cnt1=0;
                cnt0++;
                if(cnt0>k){
                    cnt1=0;
                    cnt0=1;
                    break;
                }
            }
        } 
        i--;
        int ans=i;
        // cout << "here3 " << i << " " << cnt1 << " "<< cnt0 << endl;
        bool flag = solve(s, i);
        if(flag){
            cout << ans+1 << endl;
            continue;
        }
        int p = k;
        if(cnt1){
            for(int j=i+1; j<n; j++){
                if(s[j]=='1')p++;
                else break;
            }
        }else{
            // cout << p << endl;
            for(int j=i+1; j<n; j++){
                if(s[j]=='0'){
                    p++;
                }
                else{
                    break;
                }
            }
        }
        // cout << i << " " << p << endl;

        p-=k;
        if(p>k){
            i+=p-k;
        }else if(p<k){
            i-=k-p;
        }
        // cout << "here4 " << i << endl;
        ans=i;
        flag = solve(s, i);
        
        if(flag){
            cout << ans+1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}