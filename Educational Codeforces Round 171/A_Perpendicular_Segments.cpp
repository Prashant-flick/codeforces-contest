#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int x,y,k;
        cin >> x >> y >> k;
        int ax=0,bx=min(x,y);
        int cy=y;
        int ay=0,by=min(x,y);
        int cx=0;
        int dx,dy;
        if(x==y){
            dx=x;
            dy=0;
        }else{
            dx=min(x,y);
            dy=cy-dx;
        }
        cout << ax << " " << ay << " " << bx << " " << by << endl;
        cout << cx << " " << cy << " " << dx << " " << dy << endl;
    }
}