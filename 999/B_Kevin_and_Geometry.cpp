#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int maxi=-1;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
            if(mp[arr[i]]>=4){
                maxi=arr[i];
            }
        }
        if(maxi!=-1){
            for(int i=0; i<4; i++){
                cout << maxi << " ";
            }
            cout << endl;
            continue;
        }

        int maxi1=-1;
        int maxi2=-1;
        for(auto &it: mp){
            if(it.second>=2 && maxi1==-1){
                maxi1=it.first;
            }else if(it.second>=2 && maxi2==-1){
                maxi2=it.first;
                break;
            }
        }
        if(maxi1!=-1 && maxi2!=-1){
            cout << maxi1 << " " << maxi1 << " " << maxi2 << " " << maxi2 << endl;
            continue;
        }

        sort(arr, arr+n);
        map<int,vector<pair<int,int>>> mp1;
        for(int i=1; i<n; i++){
            if(arr[i]-arr[i-1]>0){
                mp1[arr[i]-arr[i-1]].push_back({arr[i], arr[i-1]});
            }
        }


        bool flag=false;
        bool flag1=false;
        maxi1=-1;
        maxi2=-1;
        int maxi3=-1;
        for(auto &it: mp){
            if(it.second==3){
                int a = it.first*2-1;
                auto it1 = mp1.begin();
                if(it1->first>a){
                    break;
                }
                maxi1=it.first;
                maxi2=it1->second[0].first;
                maxi3=it1->second[0].second;
                flag=true;
                break;
            }else if(it.second==2){
                int a = it.first*2-1;
                int b = lower_bound(arr, arr+n, it.first) - arr;
                b--;
                int c = upper_bound(arr, arr+n, it.first) - arr;
                if(b>=0 && c<n){
                    if(arr[c]-arr[b]<=a){
                        maxi1=it.first;
                        maxi3=arr[b];
                        maxi2=arr[c];
                        flag=true;
                        break;
                    }
                }
                auto it1 = mp1.begin();
                if(it1->first>a){
                    break;
                }
                for(auto &it1: mp1){
                    if(it1.first>a){
                        flag1=true;
                        break;
                    }
                    for(pair<int,int> &p: it1.second){
                        if(p.first!=it.first && p.second!=it.first){
                            maxi1=it.first;
                            maxi2=p.first;
                            maxi3=p.second;
                            flag=true;
                            break;
                        }
                    }
                    if(flag || flag1)break;
                }
            }
            if(flag || flag1)break;
        }

        if(!flag){
            cout << -1 << endl;
        }else{
            cout << maxi1 << " " << maxi1 << " " << maxi3 << " " << maxi2 << endl;
        }
    }
}