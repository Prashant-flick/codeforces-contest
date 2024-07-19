#include <bits/stdc++.h>
using namespace std;

#define int int

int gcd(int a, int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
int findlcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
}
 
vector<int> arr;
int n;
int ans;

void solve(int i, int size, int lcm, int check){
    if(i>=n){
        return;
    }
    if(size>=1 && check==1){
        lcm = findlcm(lcm, arr[i]);
        // cout << lcm << endl;
        bool flag=true;
        for(int j=0; j<n; j++){
            if(lcm==arr[j]){
                flag=false;
                break;
            }
        }
        if(flag)ans = max(ans, size);
        // if(lcm!=arr[i])ans = max(ans, size);
    }
    //taken
    solve(i+1, size+1, lcm, 1);
    //not_taken
    solve(i+1, size-1, lcm, -1);
    return;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        ans=0;
        solve(-1, 0, 1, 0);

        cout << ans << endl;
        arr.clear();
    }
    
}