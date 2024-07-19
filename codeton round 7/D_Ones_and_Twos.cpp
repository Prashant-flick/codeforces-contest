#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        while (q--)
        {
            int x,y,z;
            cin >> x;
            if(x==1){
                cin >> y;
                int target=y;
                int i=0;
                int j=0;
                int sum=0;
                bool flag=false;
                while(j<=n){
                    if(sum<target){
                        if(j==n)break;
                        sum+=arr[j];
                        j++;
                    }else if(sum==target){
                        flag = true;
                        break;
                    }else if(sum>target){
                        sum-=arr[i];
                        i++;
                    }
                }
                if (flag)
                {
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
                
            }else{
                cin >> y >> z;
                arr[y-1]=z;
            }
        }
        
    }
    
    return 0;
}