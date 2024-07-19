#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();
        int sum = 0;
        for(int i=0; i<m; i++){
            int cnt=0;
            int k=i;
            for(int j=0; j<n; j++){
                if(a[j]==b[k]){
                    k++;
                    cnt++;
                }
            }
            sum = max(cnt, sum);
        }

        cout << n+m-sum << endl;
    }
}