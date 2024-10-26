#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            brr[i]=arr[i];
        }

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i]==arr[i+1])ans++;
        }

        int res=ans;
        for(int i=0; i<n-1; i++){
            int j=n-i-1;
            if(arr[i]==arr[i+1]){
                int a=0,b=0;
                if(i>0 && arr[i]==arr[i-1]){
                    a--;
                }
                if(i<n-1 && arr[i]==arr[i+1]){
                    a--;
                }
                if(j>0 && arr[j]==arr[j-1]){
                    a--;
                }
                if(j<n-1 && arr[j]==arr[j+1]){
                    a--;
                }
                int i1=i+1;
                int j1=n-i1-1;
                if(i1>0 && arr[i1]==arr[i1-1]){
                    b--;
                }
                if(i1<n-1 && arr[i1]==arr[i1+1]){
                    b--;
                }
                if(j1>0 && arr[j1]==arr[j1-1]){
                    b--;
                }
                if(j1<n-1 && arr[j1]==arr[j1+1]){
                    b--;
                }
                swap(arr[i], arr[j]);
                if(i>0 && arr[i]==arr[i-1]){
                    a++;
                }
                if(i<n-1 && arr[i]==arr[i+1]){
                    a++;
                }
                if(j>0 && arr[j]==arr[j-1]){
                    a++;
                }
                if(j<n-1 && arr[j]==arr[j+1]){
                    a++;
                }
                swap(arr[i], arr[j]);
                swap(arr[i1], arr[j1]);
                if(i1>0 && arr[i1]==arr[i1-1]){
                    b++;
                }
                if(i1<n-1 && arr[i1]==arr[i1+1]){
                    b++;
                }
                if(j1>0 && arr[j1]==arr[j1-1]){
                    b++;
                }
                if(j1<n-1 && arr[j1]==arr[j1+1]){
                    b++;
                }
                if(a<0 || b<0){
                    if(a<b){
                        res-=abs(a);
                        swap(arr[i1], arr[j1]);
                        swap(arr[i], arr[j]);
                    }else{
                        res-=abs(b);
                        i++;
                    }
                }else{
                    swap(arr[i1], arr[j1]);
                }
            }
        }

        int res2=ans;
        for(int i=n-1; i>0; i--){
            int j=n-i-1;
            if(brr[i]==brr[i-1]){
                int a=0,b=0;
                if(i>0 && brr[i]==brr[i-1]){
                    a--;
                }
                if(i<n-1 && brr[i]==brr[i+1]){
                    a--;
                }
                if(j>0 && brr[j]==brr[j-1]){
                    a--;
                }
                if(j<n-1 && brr[j]==brr[j+1]){
                    a--;
                }
                int i1=i-1;
                int j1=n-i1-1;
                if(i1>0 && brr[i1]==brr[i1-1]){
                    b--;
                }
                if(i1<n-1 && brr[i1]==brr[i1+1]){
                    b--;
                }
                if(j1>0 && brr[j1]==brr[j1-1]){
                    b--;
                }
                if(j1<n-1 && brr[j1]==brr[j1+1]){
                    b--;
                }
                swap(brr[i], brr[j]);
                if(i>0 && brr[i]==brr[i-1]){
                    a++;
                }
                if(i<n-1 && brr[i]==brr[i+1]){
                    a++;
                }
                if(j>0 && brr[j]==brr[j-1]){
                    a++;
                }
                if(j<n-1 && brr[j]==brr[j+1]){
                    a++;
                }
                swap(brr[i], brr[j]);
                swap(brr[i1], brr[j1]);
                if(i1>0 && brr[i1]==brr[i1-1]){
                    b++;
                }
                if(i1<n-1 && brr[i1]==brr[i1+1]){
                    b++;
                }
                if(j1>0 && brr[j1]==brr[j1-1]){
                    b++;
                }
                if(j1<n-1 && brr[j1]==brr[j1+1]){
                    b++;
                }
                if(a<0 || b<0){
                    if(a<b){
                        res2-=abs(a);
                        swap(brr[i1], brr[j1]);
                        swap(brr[i], brr[j]);
                    }else{
                        res2-=abs(b);
                        i--;
                    }
                }else{
                    swap(brr[i1], brr[j1]);
                }
            }
        }
        cout << min(res,res2) << endl;
    }
}