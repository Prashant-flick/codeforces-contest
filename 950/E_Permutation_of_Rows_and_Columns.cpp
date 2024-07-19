#include <bits/stdc++.h>
using namespace std;

typedef long long ll;   


vector<vector<ll>> transpose(vector<vector<ll>> mat)
{
  ll n = mat.size();
  vector<vector<ll>> t(n, vector<ll>(n));
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < n; j++) 
    {
      t[j][i] = mat[i][j];
    }
  }
  return t;
}

void sol() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> grid1(n, vector<ll>(m, 0));
    vector<vector<ll>> grid2(n, vector<ll>(m, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid1[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid2[i][j];
        }
    }

if(n == m) {
    set<set<ll>> stt;
    for(auto &v:grid1) {
        set<ll> cur(v.begin(), v.end());
        stt.insert(cur);
    }
    for(auto &v:grid2) {
        set<ll> cur(v.begin(), v.end());
        if(stt.count(cur) == 0) {
            cout << "NO" << endl;
            return;
        }
    }


    grid1 = transpose(grid1);
    grid2 = transpose(grid2);
    while(stt.size()) {
        stt.erase(stt.begin());
    }

    for(auto &v:grid1) {
        set<ll> cur(v.begin(), v.end());
        stt.insert(cur);
    }
    for(auto &v:grid2) {
        set<ll> cur(v.begin(), v.end());
        if(stt.count(cur) == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}else {

    set<set<ll>> stt;
    for(auto &v:grid1) {
        set<ll> cur(v.begin(), v.end());
        stt.insert(cur);
    }
    for(auto &v:grid2) {
        set<ll> cur(v.begin(), v.end());
        if(stt.count(cur) == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    while(stt.size()) {
        stt.erase(stt.begin());
    }

    for(int j=0; j<m; j++) {
        set<ll> cur;
        for(int i=0; i<n; i++) {
            cur.insert(grid1[i][j]);
        }
        stt.insert(cur);
    }
    for(int j=0; j<m; j++) {
        set<ll> cur;
        for(int i=0; i<n; i++) {
            cur.insert(grid2[i][j]);
        }
        if(stt.count(cur) == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}
    
}


int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();

    return 0;
}