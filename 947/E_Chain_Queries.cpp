#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define pb push_back
#define seti set<int>
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph;
vector<seti> black;
vi par, deg, col;
int cnt[4];

void dfs(int x, int p) {
    par[x] = p;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
}

void upd(int x, int v) {
    if(deg[x] <= 2) cnt[deg[x]]--;
    else cnt[3]--;
    deg[x] = v;
    if(deg[x] <= 2) cnt[deg[x]]++;
    else cnt[3]++;
}

void ins(int x) {
    int p = par[x];
    col[x] = 1;
    deg[x] = 0;
    cnt[0]++;
    if(col[p]) {
        upd(p, deg[p]+1);
        if(black[p].size() <=1) {
            upd(x, deg[x]+1);
        }
        else if(black[p].size() == 2) {
            for(auto e : black[p]) {
                upd(e, deg[e]-1);
            }
        }
    }
    black[p].insert(x);
    if(black[x].size() <= 2) {
        for(auto e : black[x]) {
            upd(e, deg[e]+1);
        }
    }
    upd(x, deg[x] + black[x].size());
}

void rem(int x) {
    int p = par[x];
    col[x] = 0;
    if(deg[x] >= 3) cnt[3]--;
    else cnt[deg[x]]--;
    deg[x] = 0;
    black[p].erase(x);
    if(col[p]) {
        upd(p, deg[p]-1);
        if(black[p].size() == 2) {
            for(auto e : black[p]) {
                upd(e, deg[e]+1);
            }
        }
    }
    if(black[x].size()<=2) {
        for(auto e : black[x]) {
            upd(e, deg[e]-1);
        }
    }
}

int main() {
    int t;
    scd(t);

    frange(_, t) {
        int n, q;
        scd(n);
        scd(q);
        par = deg = col = vi(n+1);
        vi colt(n+1);
        forr(i, 1, n+1) scd(colt[i]);

        frange(i, 4) cnt[i] = 0;

        graph = vvi(n+1);
        black = vector<seti>(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        dfs(1, 0);

        forr(i, 1, n+1) {
            if(colt[i]) ins(i);
        }

        frange(i, q) {
            int u;
            scd(u);
            if(col[u]) {
                rem(u);
            }
            else ins(u);
            // frange(j, 4) printf("%d ", cnt[j]);
            if((cnt[3] + cnt[0] == 0 && cnt[1] == 2) || (cnt[0] + cnt[1] + cnt[2] + cnt[3] == 1)) {
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
}