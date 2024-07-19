#include <bits/stdc++.h>
using namespace std;
// #define ll long long;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        int minA=INT_MAX;
        int minB=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]<minA){
                minA=a[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if(b[i]<minB){
                minB=b[i];
            }
        }
        long long sum1=0,sum2=0;
        //for row
        for(int i=0; i<n; i++){
            sum1+=a[i]+minB;
            sum2+=b[i]+minA;
        }
        cout << min(sum1,sum2) << endl;
    }
    
    return 0;
}