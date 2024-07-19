#include <bits/stdc++.h>
using namespace std;

bool solve(int m, int n, int *arr){
    int a = 0;
    int b;
    int c = 0;
    if(arr[0]>=m){
        b = 1;
    }
    else{
        b = -1;
    }

    int i=1;
    for(; i<n; i++){
        if( a > c){
            a = c;
        }
        c = b;

        if(arr[i] >= m)b++;
        else b--;

        if(b-a>0)return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int low = -1;
        int high = 1000000009+1;
        int m = (low+high)/2;
        while(high-low > 1){
            m = (low+high)/2;

            bool flag = solve(m, n, arr);

            if(flag){
                low = m;
            }else{
                high=m;
            }
        }

        cout << low << endl;
    }
    return 0;
}
