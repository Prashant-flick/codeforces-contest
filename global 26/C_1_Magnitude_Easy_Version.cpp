#include <bits/stdc++.h>
using namespace std;

#define int long long
int m;

int solve(vector<int>& vec, int i){
    if(i>=m){
        return 0;
    }

    int neg = vec[i] + solve(vec, i+1);
    int pos = vec[i] + solve(vec, i+1);

    // cout << pos << " " << neg << endl;

    return max(neg, abs(pos));
}

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        vector<int> vec;
        int sum=0;
        for(int i=0; i<n; i++){
            int sum=0;
            if(arr[i]<=0){
                for(; i<n; i++){
                    if(arr[i]>0){
                        break;
                    }
                    sum+=arr[i];
                }
                vec.push_back(sum);
                sum=0;
                i--;
            }else if(arr[i]>=0){
                for(; i<n; i++){
                    if(arr[i]<0){
                        break;
                    }
                    sum+=arr[i];
                }
                vec.push_back(sum);
                sum=0;
                i--;
            }
        }
        if(sum!=0){
            vec.push_back(sum);
            sum=0;
        }

        m = vec.size();

        if(m==1){
            cout << abs(vec[0]) << endl;
            continue;
        }

        int i=0;

        // if(vec[i]>0){
        //     while(vec[i]>=0 && i<m-1){
        //         vec[i+1]=vec[i]+vec[i+1];
        //         i++;
        //     }
        // }

        cout << solve(vec, i) << endl;

        // while(i<m-2){
        //     if((abs(vec[i])+vec[i+1]+vec[i+2])>=abs(vec[i]+vec[i+1]+vec[i+2])){
        //         vec[i+2]=(abs(vec[i])+vec[i+1]+vec[i+2]);
        //     }else{
        //         vec[i+2]=vec[i]+vec[i+1]+vec[i+2];
        //     }
        //     i+=2;
        // }

        // if(i>=m){
        //     i=m-1;
        // }
        // int ans = abs(vec[i]);

        // i++;
        // if(i<m){
        //     ans+=vec[i];
        // }

        // cout << ans << endl;
    }
    
}