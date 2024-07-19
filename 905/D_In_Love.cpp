#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int i=0;
    priority_queue<int> pqf;
    priority_queue<int, vector<int>, greater<int>> pqs;
    unordered_map<int,int> first;
    unordered_map<int,int> second;
    while (i<t)
    {
        char ch;
        cin >> ch;
        int f;
        int s;
        cin >> f;
        cin >> s;
        // cout << ch << " " << f << " " << s << endl;
        if(ch=='+'){
            first[f]++;
            pqf.push(f);
            second[s]++;
            pqs.push(s);
        }else{
            first[f]--;
            if(first[f]==0){
                first.erase(f);
            }
            second[s]--;
            if (second[s]==0)
            {
                second.erase(s);
            }
        }
        if(i==0){
            cout << "NO" << endl;
        }else{
            while(pqf.size()>0 && first.find(pqf.top())==first.end()){
                pqf.pop();
            }
            while(pqs.size()>0 && second.find(pqs.top())==second.end()){
                pqs.pop();
            }
            // cout << pqf.top() << " " << pqs.top() << endl;
            if(pqf.top()>pqs.top()){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }


        i++;
    }
    
    return 0;
}