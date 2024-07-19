#include <bits/stdc++.h>


using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;
        if(n==1)    cout<<0<<endl;
        else if(n<=k)    cout<<1<<endl;
        else if((n-k)%(k-1)!=0)  cout<<(n-k)/(k-1)+2<<endl;
        else    cout<<(n-k)/(k-1)+1<<endl;
    }
    return 0;
}