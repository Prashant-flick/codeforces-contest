#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
 
		string s;
		cin >> s;
		int n = s.length();
		if(s == "()") {
			cout << "no";
		}
		else {
			cout << "yes\n";
			if(s.find("((") !=  string::npos || s.find("))") !=  string::npos) {
				for(int i = 0; i<n; ++i) cout << "()";
			}
			else {
				for(int i = 0; i<n; ++i) cout << "(";
				for(int i = 0; i<n; ++i) cout << ")";
			}
		}
		
 
		cout << "\n";
	}
	return 0;
}