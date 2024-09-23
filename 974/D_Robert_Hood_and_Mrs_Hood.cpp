#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n,d,k;
        cin >> n >> d >> k;

        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> dp(n,0);
        int k1=k;
        while(k1--){
            int l,r;
            cin >> l >> r;
            mp1[l]++;
            mp2[r]++;
        }

        int i=1,j=1;
        int ans1=-1;
        int ans2=-1;
        int es = 0;
        int ee = 0;
        int s = 0;
        int e = 0;
        int maxi = INT_MIN;
        int maxi2 = INT_MAX;
        while(j<=n){
            if(j-i+1<d){
                s+=mp1[j];
                e+=mp2[j];
                j++;
            }else{
                s+=mp1[j];
                e+=mp2[j];
                int temp = es-ee;
                temp += s;
                if(temp>maxi){
                    maxi=temp;
                    ans1=((j-d)+1);
                }
                if(temp<maxi2){
                    maxi2=temp;
                    ans2=((j-d)+1);
                }
                es+=mp1[i];
                ee+=mp2[i];
                s-=mp1[i];
                e-=mp2[i];
                i++;
                j++;
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
}