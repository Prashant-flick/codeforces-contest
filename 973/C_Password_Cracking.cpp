#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,a;

void solve1(string &s){
    if(s.size()==n)return;
    s = "1"+s;
    cout << "? " << s << endl;
    cin >> a;
    if(a==1){
        if(s.size()==n)return;
        solve1(s);
    }else{
        s.erase(0,1);
        s = "0"+s;
        if(s.size()==n){
            return;
        }
        cout << "? " << s << endl;
        cin >> a;
        if(a==1){
            if(s.size()==n)return;
            solve1(s);
        }
    }
}

void solve(string &s){
    if(s.size()==n)return;
    s+="1";
    cout << "? " << s << endl;
    cin >> a;
    if(a==1){
        if(s.size()==n)return;
        solve(s);
    }else{
        s.pop_back();
        s+="0";
        cout << "? " << s << endl;
        cin >> a;
        if(a==1){
            if(s.size()==n)return;
            solve(s);
        }else{
            s.pop_back();
            solve1(s);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        cin >> n;
        string s = "1";
        cout << "? " << s << endl;
        cin >> a;
        if(a==1){
            solve(s);
            cout << "! " << s << endl;
            continue;
        }else{
            s="0";
            for(int i=1; i<n; i++){
                s+="0";
            }
            cout << "! " << s << endl;
            continue;
        }

        s = "0";
        cout << "? " << s << endl;
        cin >> a;
        if(a==1){
            solve(s);
            cout << "! " << s << endl;
            continue;
        }else{
            s="1";
            for(int i=1; i<n; i++){
                s+="1";
            }
            cout << "! " << s << endl;
            continue;
        }

    }
}