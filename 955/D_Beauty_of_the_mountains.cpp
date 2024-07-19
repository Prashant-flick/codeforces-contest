#include <bits/stdc++.h>
using namespace std;

#define int long long
bool flag=false;

void solve(vector<int> &vec, int a, int i, int n){
    if(i>=n || flag){
        return;
    }
    // cout << vec[i] << endl;
    if(a%vec[i]==0){
        flag=true;
        return;
    }
    
    
    solve(vec, a%vec[i], i+1, n);
    solve(vec, a, i+1, n);
    return;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        
        string s[n];
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<n; i++){
            cin >> s[i];
            for(int j=0; j<m; j++){
                if(s[i][j]=='1'){
                    sum1+=arr[i][j];
                }else{
                    sum2+=arr[i][j];
                }
            }
        }

        if(sum1==sum2){
            cout << "YES" << endl;
            continue;
        }

        int maxsize = k*k;
        map<int, int, greater<int> > mp;
        int p=0;
        while(p<=n-k){
            int sumi = 0;
            int brr[m];
            for(int j=0; j<m; j++){
                int i=p;
                for(; i<k+p; i++){
                    if(s[i][j]=='1'){
                        sumi++;
                    }
                }
                brr[j]=sumi;
            }

            mp[abs((brr[k-1])-(maxsize-brr[k-1]))]=true;
            for(int i=k; i<m; i++){
                int num =brr[i]-brr[i-k];
                mp[abs((num)-(maxsize-num))]=true;
            }

            p++;
        }

        vector<int> vec;
        auto it = mp.begin();
        while(it!=mp.end()){
            if(it->first==0){
                it++;
                continue;
            }
            vec.push_back(it->first);
            it++;
        }

        int a = abs(sum1-sum2);
        flag=false;
        // cout << a << " " << vec.size() << endl;
        solve(vec, a, 0, vec.size());

        // auto it = mp.begin();
        // bool flag = false;
        // int a = abs(sum1-sum2);
        // int a1 = a;
        // while(it!=mp.end()){
        //     int num = it->first;
        //     // cout << num << " " << a << " " << maxsize << endl;
        //     if(num!=0 && a%num==0){
        //         flag=true;
        //         break;
        //     }else if(num!=0){
        //         a=a%num;
        //         if(mp.find(a)!=mp.end() || mp.find(a1%num)!=mp.end()){
        //             flag=true;
        //             break;
        //         }
        //     }
        //     it++;
        // }
        
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}