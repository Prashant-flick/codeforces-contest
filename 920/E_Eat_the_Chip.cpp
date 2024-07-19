#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int h,w,x1,y1,x2,y2;
        cin >> h >> w >> x1 >> y1 >> x2 >> y2;
        int a=h-x1;
        int b=x2-1;
        if(x1>=x2){
            cout << "Draw" << endl;
        }else{
            
            if((x2-x1)%2==0){
                if(y1==y2){
                    cout << "Bob" << endl;
                }else if(y1<y2){
                    y2-=1;
                    x2-=y2;
                    x1+=y2;
                    if(x1<=x2){
                        cout << "Bob" << endl;
                    }else{
                        cout << "Draw" << endl;
                    }
                }else if(y1>y2){
                    y2 = w-y2;
                    x2-=y2;
                    x1+=y2;
                    if(x1<=x2){
                        cout << "Bob" << endl;
                    }else{
                        cout << "Draw" << endl;
                    }
                }
            }else{
                if(abs(y1-y2)<=1){
                    cout << "Alice" << endl;
                }else if(y1<y2-1){
                    y1=w-y1-1;
                    x2-=y1;
                    x1+=y1;
                    if(x1+1<=x2){
                        cout << "Alice" << endl;
                    }else{
                        cout << "Draw" << endl;
                    }
                }else if(y2<y1-1){
                    y1-=2;
                    x2-=y1;
                    x1+=y1;
                    if(x1+1<=x2){
                        cout << "Alice" << endl;
                    }else{
                        cout << "Draw" << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}