#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    GCD(b,a%b);
}

int main(){
    cout << GCD(15,12) << endl;
    cout << GCD(30,15) << endl;
    cout << GCD(21,132) << endl;
    cout << GCD(432,112) << endl;
    cout << GCD(432,0) << endl;
    cout << GCD(0,112) << endl;
    return 0;
}