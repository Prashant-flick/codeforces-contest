    #include<bits/stdc++.h>
    using namespace std;

    #define int long long

    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);

        int t;
        cin >> t;
        while(t--){
            int n,l,r;
            cin >> n;
            int brr[n];
            map<int,int> mp;
            vector<int> cnt;
            vector<pair<int,int>> vec(n);
            for(int i=0; i<n; i++){
                cin >> l >> r;
                vec[i]=make_pair(l,r);
                if(l==r){
                    if(mp.find(l)==mp.end()){
                        cnt.push_back(l);
                    }
                    mp[l]++;
                    brr[i]=l;
                }else{
                    brr[i]=0;
                }
            }

            sort(cnt.begin(), cnt.end());

            for(int i=0; i<n; i++){
                if(brr[i]!=0){
                    if(mp.find(brr[i])!=mp.end()){
                        if(mp[brr[i]]>1){
                            cout << 0;
                        }else{
                            cout << 1;
                        }
                    }else{
                        cout << 1;
                    }
                }else{
                    if(mp.size()<(vec[i].second-vec[i].first+1)){
                        cout << 1;
                    }else{
                        if(mp.find(vec[i].first)!=mp.end() && mp.find(vec[i].second)!=mp.end()){
                            int a = lower_bound(cnt.begin(), cnt.end(), vec[i].first)-cnt.begin();
                            int b = lower_bound(cnt.begin(), cnt.end(), vec[i].second)-cnt.begin();
                            if(b-a+1==vec[i].second-vec[i].first+1){
                                cout << 0;
                            }else{
                                cout << 1;
                            }
                        }else{
                            cout << 1;
                        }
                    }
                }
            }
            cout << endl;
        }
    }