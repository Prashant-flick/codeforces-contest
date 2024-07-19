#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[5];
        arr[0]=15;
        arr[1]=10;
        arr[2]=6;
        arr[3]=3;
        arr[4]=1;
        int res = n;

        for(int i=0; i<1; i++){
            int a = n;
            int ans1 =  (a / arr[i]);
            a%=arr[i];
            for(int j=i+1; j<=i+1; j++){
                int b = a;
                int ans2 = ans1;
                ans1 += (a /arr[j]);
                a%=arr[j];
                for(int k=j+1; k<=j+1; k++){
                    int c = b;
                    int ans3 = ans2;
                    ans2 += (b/arr[k]);
                    b %= arr[k];
                    ans1 += a%arr[k];
                    a%=arr[k];
                    for(int l=k+1; l<=k+1; l++){
                        int d = c;
                        int ans4 = ans3;
                        ans3 += c/arr[l];
                        c %= arr[l];
                        ans2 += b/arr[l];
                        b%=arr[l];
                        ans1 += a/arr[l];
                        a%=arr[l];
                        for(int m=l+1;m<=l+1;m++){
                            ans1 += a;
                            ans2 += b;
                            ans3 += c;
                            ans4 += d;
                            res = min(res, min(ans1, min(ans2, min(ans3, ans4))));
                        }
                    }
                }
            }
        }

        for(int j=1; j<=1; j++){
            int b = n;
            int ans2 = 0;
            ans2 += (b /arr[j]);
            b%=arr[j];
            for(int k=j+1; k<=j+1; k++){
                int c = b;
                int ans3 = ans2;
                ans2 += (b/arr[k]);
                b %= arr[k];
                for(int l=k+1; l<=k+1; l++){
                    int d = c;
                    int ans4 = ans3;
                    ans3 += c/arr[l];
                    c %= arr[l];
                    ans2 += b/arr[l];
                    b%=arr[l];
                    for(int m=l+1;m<=l+1;m++){
                        ans2 += b;
                        ans3 += c;
                        ans4 += d;
                        res = min(res, min(ans2, min(ans3, ans4)));
                    }
                }
            }
        }

        for(int k=2; k<=2; k++){
            int c = n;
            int ans3 = 0;
            ans3 += (c/arr[k]);
            c%=arr[k];
            for(int l=k+1; l<=k+1; l++){
                int d = c;
                int ans4 = ans3;
                ans3 += c/arr[l];
                c %= arr[l];
                for(int m=l+1;m<=l+1;m++){
                    ans3 += c;
                    ans4 += d;
                    res = min(res, min(ans3, ans4));
                }
            }
        }

        for(int l=3; l<=3; l++){
            int d = n;
            int ans4 = 0;
            ans4 += d/arr[l];
            d%=arr[l];
            for(int m=l+1;m<=l+1;m++){
                ans4 += d;
                res = min(res, ans4);
            }
        }
        cout << res << endl;
    }
}