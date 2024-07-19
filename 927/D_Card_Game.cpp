#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char ch;
        cin >> ch;
        int trump=0;
        vector<int> S;
        vector<int> C;
        vector<int> D;
        vector<int> H;
        for(int i=0; i<(2*n); i++){
            string s;
            cin >> s;
            if(s[1]=='S'){
                S.push_back(s[0]-'0');
            }else if(s[1]=='D'){
                D.push_back(s[0]-'0');
            }else if(s[1]=='C'){
                C.push_back(s[0]-'0');
            }else{
                H.push_back(s[0]-'0');
            }
            if(s[1]==ch)trump++;
        }

        trump += ((ch!='S'? S.size()/2 : 0) + (ch!='D'? D.size()/2 : 0) + (ch!='H'? H.size()/2 : 0) + (ch!='C'? C.size()/2 : 0));

        if(trump < n){
            cout << "IMPOSSIBLE" << endl;
        }else{
            sort(S.begin(), S.end());
            sort(D.begin(), D.end());
            sort(H.begin(), H.end());
            sort(C.begin(), C.end());
            int i=0;
            int s=0;
            int d=0;
            int c=0;
            int h=0;

            while(i<n && 'S'!=ch && s<S.size()){
                int p,q;
                p=S[s];
                s++;
                if(s<S.size()){
                    q=S[s++];
                }else{
                    s--;
                    break;
                }
                cout << p << "S" << " "<< q << "S" << endl;
                i++;
            }
            while(i<n && 'D'!=ch && d<D.size()){
                int p,q;
                p=D[d];
                d++;
                if(d<D.size()){
                    q=D[d++];
                }else{
                    d--;
                    break;
                }
                cout << p << "D" << " "<< q << "D" << endl;
                i++;
            }
            while(i<n && 'C'!=ch && c<C.size()){
                int p,q;
                p=C[c++];
                if(c<C.size()){
                    q=C[c++];
                }else{
                    c--;
                    break;
                }
                cout << p << "C" << " "<< q << "C" << endl;
                i++;
            }
            while(i<n && 'H'!=ch && h<H.size()){
                int p,q;
                p=H[h++];
                if(h<H.size()){
                    q=H[h++];
                }else{
                    h--;
                    break;
                }
                cout << p << "H" << " "<< q << "H" << endl;
                i++;
            }


            // second part
            while(i<n && 'S'!=ch && s<S.size()){
                int p,q;
                p=S[s++];
                if(ch=='D'){
                    q=D[d++];
                }else if(ch=='C'){
                    q=C[c++];
                }else{
                    q=H[h++];
                }
                cout << p << "S" << " "<< q << ch << endl;
                i++;
            }
            while(i<n && 'D'!=ch && d<D.size()){
                int p,q;
                p=D[d++];
                if(ch=='S'){
                    q=S[s++];
                }else if(ch=='C'){
                    q=C[c++];
                }else{
                    q=H[h++];
                }
                cout << p << "D" << " "<< q << ch << endl;
                i++;
            }
            while(i<n && 'C'!=ch && c<C.size()){
                int p,q;
                p=C[c++];
                if(ch=='D'){
                    q=D[d++];
                }else if(ch=='S'){
                    q=S[s++];
                }else{
                    q=H[h++];
                }
                cout << p << "C" << " "<< q << ch << endl;
                i++;
            }
            while(i<n && 'H'!=ch && h<H.size()){
                int p,q;
                p=H[h++];
                if(ch=='D'){
                    q=D[d++];
                }else if(ch=='C'){
                    q=C[c++];
                }else{
                    q=S[s++];
                }
                cout << p << "H" << " "<< q << ch << endl;
                i++;
            }


            //trump

            if(ch=='D'){
                while(i<n && d<D.size()){
                    int p,q;
                    p=D[d++];
                    if(d<D.size()){
                        q=D[d++];
                    }else{
                        d--;
                        break;
                    }
                    cout << p << "D" << " " << q << "D" << endl;
                    i++;
                }
            }else if(ch=='C'){
                while(i<n && c<C.size()){
                    int p,q;
                    p=C[c++];
                    if(c<C.size()){
                        q=C[c++];
                    }else{
                        c--;
                        break;
                    }
                    cout << p << "C" << " " << q << "C" << endl;
                    i++;
                }
            }else if(ch=='H'){
                while(i<n && h<H.size()){
                    int p,q;
                    p=H[h++];
                    if(h<H.size()){
                        q=H[h++];
                    }else{
                        h--;
                        break;
                    }
                    cout << p << "H" << " " << q << "H" << endl;
                    i++;
                }
            }else{
                while(i<n && s<S.size()){
                    int p,q;
                    p=S[s++];
                    if(s<S.size()){
                        q=S[s++];
                    }else{
                        s--;
                        break;
                    }
                    cout << p << "S" << " " << q << "S" << endl;
                    i++;
                }
            }
        }
        
    }
    return 0;
}