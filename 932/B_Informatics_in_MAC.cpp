#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int mex = 0;
        auto it = mp.begin();
        while(it!=mp.end()){
            if(it->first != mex){
                it->second = 0;
                while(it!=mp.end()){
                    it->second = 0;
                    it++;
                }
                break;
            }else{
                mex++;
                it++;
            }
        }

        if(mex==0){
            cout << 2 << endl;
            cout << 1 << " " << 1  << endl;
            cout << 2 << " " << n << endl;
        }else{
            it = mp.begin();
            // cout << it->first << endl;
            bool flag = true;
            while(it!=mp.end() && mex>(it->first)){
                if(it->second < 2){
                    flag = false;
                    break;
                }
                it++;
            }

            if(!flag){
                cout << -1 << endl;
            }else{
                int cnt = mex;
                unordered_map<int,bool> mp2;
                for(int i=0; i<mex; i++){
                    mp2[i] = true;
                }
                int i;
                for(i=0; i<n; i++){
                    if(mp[arr[i]]!=0){
                        mp[arr[i]]--;
                        if(mp[arr[i]]<1){
                            flag = false;
                            break;
                        }
                        if(mp2[arr[i]]){
                            cnt--;
                        }
                        mp2[arr[i]]=false;
                        if(cnt==0){
                            break;
                        }
                    }
                }

                if(flag){
                    cout << 2 << endl;
                    cout << 1 << " " << i+1 << endl;
                    cout << i+2 << " " << n << endl;
                }else{
                    cout << -1 << endl;
                }

            }
        }

    }
}