#include<bits/stdc++.h>
using namespace std;

int n,m;
int res1=0;
int res2=0;

void solve(int i, int j, int prev, int cnt){
    if(i==5 && j==5){
        if(cnt%2==0){
            res2++;
        }
        res1++;
        return;
    }
    if(j==5 && i!=5){
        solve(i+1, j, 1, (prev==0?cnt+1:cnt));
    }
    else if(i==5 && j!=5){
        solve(i, j+1, 0, (prev==1?cnt+1:cnt));
    }else{
        solve(i+1, j, 1, (prev==0?cnt+1:cnt));
        solve(i, j+1, 0, (prev==1?cnt+1:cnt));
    }
    return;
}

int main(){
    cin >> n >> m;

    cout << "here" << endl;
    solve(1,1, -1, 0);
    cout << "here" << endl;
    cout << res1 << " " << res2 << endl;
    cout << res2/res1 << endl;
    cout << (1<<14) << endl;
}