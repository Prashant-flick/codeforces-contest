#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n<7){
            cout << "NO" << endl;
        }else{
            int num1,num2,num3;
            int i=2;
            bool flag = false;
            num1=1;
            int t=n;
            n-=1;
            while((n-i)>i){
                if(i%3!=0 && (n-i)%3!=0){
                    num2=i;
                    num3=(n-i);
                    flag = true;
                    break;
                }
                i++;
            }
            if(!flag){
                num1=2;
                i=3;
                t-=2;
                while((t-i)>i){
                    if(i%3!=0 && (t-i)%3!=0){
                        num2=i;
                        num3=(t-i);
                        flag = true;
                        break;
                    }
                    i++;
                }
            }
            if(flag){
                cout << "YES" << endl;
                cout << num1 << " " << num2 << " " << num3 << endl;
            }else{
                cout << "NO" << endl;
            }
        }
       
    }
    
    return 0;
}