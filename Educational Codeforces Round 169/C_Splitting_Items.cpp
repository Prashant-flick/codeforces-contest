  #include<bits/stdc++.h>
  using namespace std;

  int main(){
    int t;
    cin >> t;
    while (t--)
    {
      int n,k;
      cin >> n >> k;
      vector<int> arr(n);
      for(int i=0; i<n; i++)cin >> arr[i];
      sort(arr.rbegin(), arr.rend());
      int a=0;
      int b=0;
      for(int i=0; i<n; i++){
        if(i%2==0){
          a+=arr[i];
        }else{
          if(k>0){
            b+=(arr[i]);
            int temp=arr[i-1]-arr[i];
            if(k>=temp){
              b+=temp;
              k-=temp;
            }else{
              b+=k;
              k=0;
            }
          }else{
            b+=arr[i];
          }
        }
      }
      cout << a-b << endl;

    
    }
    
  }