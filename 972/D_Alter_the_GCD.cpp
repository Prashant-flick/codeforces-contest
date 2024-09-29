#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 2e5+10;
int arr[N],brr[N],gcd11[N],gcd12[N],gcd21[N],gcd22[N];

int gcd(int a, int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return gcd(a, b%a);
}

signed main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<n; i++)cin >> brr[i];

        gcd11[0]=arr[0];
        for(int i=1; i<n; i++){
            gcd11[i]=gcd(gcd11[i-1],arr[i]);
        }
        gcd12[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            gcd12[i]=gcd(gcd12[i+1],arr[i]);
        }
        gcd21[0]=brr[0];
        for(int i=1; i<n; i++){
            gcd21[i]=gcd(gcd21[i-1],brr[i]);
        }
        gcd22[n-1]=brr[n-1];
        for(int i=n-2; i>=0; i--){
            gcd22[i]=gcd(gcd22[i+1],brr[i]);
        }

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int mid1 = arr[i];
            int mid2 = brr[i]; 
            for(int j=i; j<n; j++){
                mid1 = gcd(mid1, arr[j]);
                mid2 = gcd(mid2, brr[j]);
                int gcd1=mid2;
                int gcd2=mid1;
                int a1 = (i-1>=0?gcd11[i-1]:0);
                int a3 = (j+1<n?gcd12[j+1]:0);
                if(a1==0 && a3!=0){
                    gcd1=gcd(gcd1,a3);
                }else if(a1!=0 && a3==0){
                    gcd1=gcd(gcd1,a1);
                }else if(a1!=0 && a3!=0){
                    gcd1=gcd(gcd1,a1);
                    gcd1=gcd(gcd1,a3);
                }
                int b1 = (i-1>=0?gcd21[i-1]:0);
                int b3 = (j+1<n?gcd22[j+1]:0);
                if(b1==0 && b3!=0){
                    gcd2=gcd(gcd2,b3);
                }else if(b1!=0 && b3==0){
                    gcd2=gcd(gcd2,b1);
                }else if(b1!=0 && b3!=0){
                    gcd2=gcd(gcd2,b1);
                    gcd2=gcd(gcd2,b3);
                }
                
                mp[gcd1+gcd2]++;
            }
        }

        int maxi=INT_MIN;
        int ans=0;
        for(auto &it: mp){
            if(maxi<it.first){
                maxi=it.first;
                ans=it.second;
            }
        }

        cout << maxi << " " << ans << endl;
    }
    
}