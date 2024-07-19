#include <bits/stdc++.h>
using namespace std;

// #define int long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> right;
        vector<int> left;
        for(int i=0; i<n; i++){
            if(s[i]=='<'){
                left.push_back(i);
            }else{
                right.push_back(i);
            }
        }


        for(int k=0; k<n; k++){
            int l=k;
            int ans = 0;
            if(s[k]=='<'){
                int i = lower_bound(right.begin(), right.end(), l) - right.begin();
                // if(l!=right[i]){
                //     i--;
                // }
                i--;
                int j = upper_bound(left.begin(), left.end(), l) - left.begin();
                // cout << i << " " << j << endl;
                while(true){
                    if(i>=0){
                        ans+=(abs(l - right[i]));
                        l=right[i];
                        i--;
                    }else{
                        ans+= l+1;
                        break;
                    }

                    if(j<left.size()){
                        ans+=(abs(l -left[j]));
                        l=left[j];
                        j++;
                    }else{
                        ans+= (n-l);
                        break;
                    }
                }
                

                cout << ans << " ";
            }else{
                int j = upper_bound(left.begin(), left.end(), l) - left.begin();
                int i = lower_bound(right.begin(), right.end(), l) - right.begin();
                // if(l!=right[i]){
                //     i--;
                // }
                i--;
                // cout << i << " " << j << endl;
                while(true){
                    if(j<left.size()){
                        ans+=(abs(l - left[j]));
                        l=left[j];
                        j++;
                    }else{
                        // cout << "here" << endl;
                        ans+= (n-l);
                        break;
                    }

                    if(i>=0){
                        ans+=(abs(l - right[i]));
                        l=right[i];
                        i--;
                    }else{
                        ans+=l+1;
                        break;
                    }
                }

                cout << ans << " ";
            }
        }
        cout<<endl;
    }
}
