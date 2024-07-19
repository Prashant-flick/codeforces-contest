#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> a;

bool check(int num) {
    int mn=0, curr, prv=0;
    if(a[0]>=num)
        curr = 1;
    else
        curr = -1;
    for(int i=1; i<n; i++) {
        mn = min(mn, prv);
        prv=curr;
        if(a[i] >= num)
            curr++;
        else
            curr--;
        if(curr-mn>0)
            return 1;
    }
    return 0;
}

void solve() {
    cin >> n;
    a.assign(n,0);
    for(auto &it: a)
    cin >> it;
    int l=-1, r=1e9+1;
    while(r-l>1){
        int mid = (l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    cout << l << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}