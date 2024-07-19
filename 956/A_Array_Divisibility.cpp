#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n+1);
        ans[n]=n;
        for(int i=n-1; i>0; i--){
            ans[i]=1;
            int sum=0;
            for(int j=i+1; j<=n; j++){
                if(j%i==0){
                    sum+=ans[j];
                }
            }
            ans[i]=sum+i-((sum+i)%i);
            // int temp = (sum+i)%i;
            // ans[i]+=(i-temp);
        }

        for(int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
}