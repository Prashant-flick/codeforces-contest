#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int i=0;
        for(; i<32; i++){
            if(((x>>i)&1) != ((y>>i)&1)){
                break;
            }
        }
        // i--;
        // if(i<0)i=0;
        // cout << i << endl;
        cout << (1<<i) << endl;
    }
}