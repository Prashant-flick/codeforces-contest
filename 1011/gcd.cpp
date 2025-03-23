#include<bits/stdc++.h>
using namespace std;

#define int long long
int a,sz;
vector<int> segTree;

void update(int i, int val){
    segTree[i]=val;
    i/=2;
    while(i>0){
        if(segTree[2*i+1]==0){
            segTree[i]=segTree[2*i];
        }else{
            segTree[i]=__gcd(segTree[2*i],segTree[2*i+1]);
        }
        i/=2;
    }
    return;
}

int find(int l, int r, int L, int R, int i){
    if(R<l || L>r){
        return -1;
    }else if(L>=l && R<=r){
        return segTree[i];
    }else{
        int mid = (L+R)/2;
        int x = find(l,r,L,mid,2*i);
        int y = find(l,r,mid+1,R,2*i+1);
        if(x!=-1 && y!=-1){
            return __gcd(x,y);
        }else if(x!=-1){
            return x;
        }else{
            return y;
        }
    }
}

signed main(){
    int n,q;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int pre[n];
    pre[0]=arr[0];
    for(int i=1; i<n; i++){
        pre[i]=pre[i-1]+arr[i];
    }
    a=1;
    while(a<n){
        a<<=1;
    }
    sz=a*2;
    segTree.resize(sz,0);
    for(int i=0; i<n; i++){
        update(i+a,arr[i]);
    }
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << find(l,r,0,a-1,1) << endl;
    }
}