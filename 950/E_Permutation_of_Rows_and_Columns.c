#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void transpose(ll **mat, ll n, ll **t) {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            t[j][i] = mat[i][j];
        }
    }
}

int set_compare(const void *a, const void *b) {
    return (*(ll *)a - *(ll *)b);
}

int check_sets(ll **grid1, ll **grid2, ll n, ll m) {
    ll *row1 = (ll *)malloc(m * sizeof(ll));
    ll *row2 = (ll *)malloc(m * sizeof(ll));
    if (!row1 || !row2) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            row1[j] = grid1[i][j];
            row2[j] = grid2[i][j];
        }
        qsort(row1, m, sizeof(ll), set_compare);
        qsort(row2, m, sizeof(ll), set_compare);

        int match = 1;
        for (ll j = 0; j < m; j++) {
            if (row1[j] != row2[j]) {
                match = 0;
                break;
            }
        }
        if (!match) {
            free(row1);
            free(row2);
            return 0;
        }
    }

    free(row1);
    free(row2);
    return 1;
}

void solve() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll **grid1 = (ll **)malloc(n * sizeof(ll *));
    ll **grid2 = (ll **)malloc(n * sizeof(ll *));
    for (ll i = 0; i < n; i++) {
        grid1[i] = (ll *)malloc(m * sizeof(ll));
        grid2[i] = (ll *)malloc(m * sizeof(ll));
        for (ll j = 0; j < m; j++) {
            scanf("%lld", &grid1[i][j]);
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            scanf("%lld", &grid2[i][j]);
        }
    }

    if (n == m) {
        if (!check_sets(grid1, grid2, n, m)) {
            printf("NO\n");
            for (ll i = 0; i < n; i++) {
                free(grid1[i]);
                free(grid2[i]);
            }
            free(grid1);
            free(grid2);
            return;
        }

        ll **transposed1 = (ll **)malloc(n * sizeof(ll *));
        ll **transposed2 = (ll **)malloc(n * sizeof(ll *));
        for (ll i = 0; i < n; i++) {
            transposed1[i] = (ll *)malloc(n * sizeof(ll));
            transposed2[i] = (ll *)malloc(n * sizeof(ll));
        }

        transpose(grid1, n, transposed1);
        transpose(grid2, n, transposed2);

        if (!check_sets(transposed1, transposed2, n, m)) {
            printf("NO\n");
            for (ll i = 0; i < n; i++) {
                free(grid1[i]);
                free(grid2[i]);
                free(transposed1[i]);
                free(transposed2[i]);
            }
            free(grid1);
            free(grid2);
            free(transposed1);
            free(transposed2);
            return;
        }

        printf("YES\n");
        for (ll i = 0; i < n; i++) {
            free(transposed1[i]);
            free(transposed2[i]);
        }
        free(transposed1);
        free(transposed2);
    } else {
        if (!check_sets(grid1, grid2, n, m)) {
            printf("NO\n");
            for (ll i = 0; i < n; i++) {
                free(grid1[i]);
                free(grid2[i]);
            }
            free(grid1);
            free(grid2);
            return;
        }

        printf("YES\n");
    }

    for (ll i = 0; i < n; i++) {
        free(grid1[i]);
        free(grid2[i]);
    }
    free(grid1);
    free(grid2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
