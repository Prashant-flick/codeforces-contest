#include<bits/stdc++.h>
using namespace std;

#define int long long
int solve2(double h, double k, double r, double newY) {
    double term = r * r - (newY - k) * (newY - k);

    // If term is negative, no real solutions (point outside circle)
    if (term < 0) return {};  

    double root = sqrt(term);
    return h + root;  // Two possible x values
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve2(5, 0, 2, 0) << endl;
    }
}