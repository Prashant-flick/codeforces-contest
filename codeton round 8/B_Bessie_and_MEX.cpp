#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            st.insert(i);
        }

        int mex;
        if(arr[0]<0){
            cout << abs(arr[0]) << " ";
            st.erase(abs(arr[0]));
            mex=0;
            st.erase(0);
        }else{
            cout << 0 << " ";
            st.erase(0);
            mex=1;
            st.erase(1);
        }
        
        for(int i=1; i<n; i++){
            if(st.empty()){
                cout << mex << " ";
                continue;
            }
            int a = *st.begin();
            if(a-mex==arr[i]){
                cout << mex << " ";
                mex=a;
                st.erase(a);
            }else if(st.find(mex-arr[i])!=st.end()){
                cout << mex-arr[i] << " ";
                st.erase(mex-arr[i]);
            }
        }

        cout << endl;
        
    }
    return 0;
}