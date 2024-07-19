#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int maxi;
int p1,p2;

bool solve(int *a, int *b, int*c){
    int i=0;
    int sum=0;
    while(i<n && sum<maxi){
        sum+=a[i];
        // cout << i << " " << sum << endl;
        i++;
    }
    p1=i;
    if(sum<maxi){
        return false;
    }

    sum=0;
    while(i<n && sum<maxi){
        sum+=b[i];
        // cout << i << " " << sum << endl;
        i++;
    }
    p2=i;

    if(sum<maxi)return false;

    sum=0;
    while(i<n && sum<maxi){
        sum+=c[i];
        // cout << i << " " << sum << endl;
        i++;
    }
    if(sum<maxi)return false;

    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        int b[n];
        int c[n];
        int tot=0;
        for(int i=0;i<n;i++)cin >> a[i];
        for(int i=0;i<n;i++)cin >> b[i];
        for(int i=0;i<n;i++){
            cin >> c[i];
            tot+=c[i];
        }

        maxi = tot/3 + (tot%3!=0 ? 1 : 0);

        if(solve(a,b,c)){
            cout << 1 << " " << p1 << " " << p1+1 << " " << p2 << " " << p2+1 << " " << n << endl;
            continue;
        }else if(solve(a,c,b)){
            // cout << "here2" << endl;
            cout << 1 << " " << p1 << " " << p2+1 << " " << n << " " << p1+1 << " " << p2 << endl;
            continue;
        }else if(solve(b,a,c)){
            // cout << "here3" << endl;
            cout << p1+1 << " " << p2 << " " << 1 << " " << p1 << " " << p2+1 << " " << n << endl;
            continue;
        }else if(solve(b,c,a)){
            // cout << "here4" << endl;
            cout << p2+1 << " " << n << " " << 1 << " " << p1 << " " << p1+1 << " " << p2 << endl;
            continue;
        }else if(solve(c,a,b)){
            // cout << "here5" << endl;
            cout << p1+1 << " " << p2 << " " << p2+1 << " " << n << " " << 1 << " " << p1 <<  endl;
            continue;
        }else if(solve(c,b,a)){
            // cout << "here6" << endl;
            cout << p2+1 << " " << n << " " << p1+1 << " " << p2 << " " << 1 << " " << p1 << endl;
            continue;
        }else{
            cout << -1 << endl;
        }
    }
    
}