#include <bits/stdc++.h>
using namespace std; 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n, -1);
  for (int i = 1; i < n; i++) cin >> a[i], a[i]--;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  vector<int> pos(n);
  for (int i = 0; i < n; i++) pos[p[i]] = i;
  int good = 0;
  vector<set<int>> s(n);
  vector<int> f(n);
  vector<vector<int>> adj(n);
  for (int i = n - 1; i >= 0; i--) {
    if (i > 0) adj[a[i]].push_back(i);

    for (int j : adj[i]) f[i] += f[j];

    f[i]++;
  }
  int bad = 0;

  auto calc = [&](int i) {
    if (s[i].empty()) return false;
    int x = pos[i];
    int y = *s[i].begin();
    return y < x;
  };

  auto del = [&](int i, int x) {
  auto it = s[i].find(x);
  int l = -1, r = -1;
  if (it != s[i].begin()) {
  l = *prev(it);
  if (l + f[p[l]] != x) bad--;
  }
  if (next(it) != s[i].end()) {
  r = *next(it);
  if (x + f[p[x]] != r) bad--;
  }
  if (l != -1 && r != -1) {
  if (l + f[p[l]] != r) bad++;
  }
  s[i].erase(it);
  };

  auto add = [&](int i, int x) {
  s[i].emplace(x);
  auto it = s[i].find(x);
  int l = -1, r = -1;
  if (it != s[i].begin()) {
  l = *prev(it);
  if (l + f[p[l]] != x) bad++;
  }
  if (next(it) != s[i].end()) {
  r = *next(it);
  if (x + f[p[x]] != r) bad++;
  }
  if (l != -1 && r != -1) {
   if (l + f[p[l]] != r) bad--;
  }
  };

  for (int i = 0; i < n; i++) {
  if (a[p[i]] != -1) {
    cout << a[p[i]] << endl;
    add(a[p[i]], i);
  }
  }

  for (int i = 0; i < n; i++) {
  bad += calc(i);
  }

  while (q--) {
  int x, y;
  cin >> x >> y;
  x--, y--;
      cout << x << " " << y << endl;

  set<int> change;
  change.emplace(p[x]);
  change.emplace(p[y]);
  change.emplace(a[p[x]]);
  change.emplace(a[p[y]]);
  for (int z : change) {
  if (z != -1) bad -= calc(z);
  }
  if (a[p[x]] != -1) del(a[p[x]], x);
  if (a[p[y]] != -1) del(a[p[y]], y);
  swap(p[x], p[y]);
  swap(pos[p[x]], pos[p[y]]);
  if (a[p[x]] != -1) add(a[p[x]], x);
  if (a[p[y]] != -1) add(a[p[y]], y);
  for (int z : change) {
  if (z != -1) bad += calc(z);
  }
  cout << (bad == 0 ? "YES\n" : "NO\n");
  }
  }
}
