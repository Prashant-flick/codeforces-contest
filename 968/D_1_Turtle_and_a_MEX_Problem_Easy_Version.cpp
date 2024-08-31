  #include<bits/stdc++.h>
  using namespace std;

  #define int long long

  const int N = 1e5+1;

  signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
      int n, m;
      cin >> n >> m;
      int maxi=INT_MIN;

      for(int i=0; i<n; i++){
        int n1;
        cin >> n1;
        set<int> st;
        for(int j=0; j<n1; j++){
          int temp;
          cin >> temp;
          st.insert(temp);
        }
        int f=-1;
        int s=-1;
        int k=0;
        auto it = st.begin();

        while(it!=st.end()){
          if((*it)!=k){
            if(f!=-1){
              s=k;
              break;
            }
            f=k;
            if(k+1==(*it)){
              k+=2;
            }else{
              s=k+1;
              break;
            }
          }else{
            k++;
          }
          it++;
        }
        if(f==-1){
          f=k;
          s=k+1;
        }else if(s==-1){
          s=k;
        }
        maxi=max(maxi, s);
      }

      int ans=0;
      for(int i=0; i<=min(maxi,m); i++){
        ans+=max(maxi,i);
      }
      if(min(maxi,m)!=m){
        ans = ans+(((m-maxi)*(maxi+m+1)/2));
      }
      cout << ans << endl;
    }
  }