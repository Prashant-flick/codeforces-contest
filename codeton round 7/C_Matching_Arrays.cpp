#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> a(n), b(n);
        // Input array 'a'
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Input array 'b'
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sorting arrays 'a' and 'b'
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int initial_beauty = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                initial_beauty++;
            }
        }

        // If initial beauty is already greater than or equal to 'x', no rearrangement needed
        if (initial_beauty >= x) {
            cout << "No rearrangement needed. Original 'b' array: ";
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << endl;
            return 0;
        }

        // Perform rearrangement to achieve beauty 'x'
        int swaps = x - initial_beauty;
        int i = 0, j = n - 1;
        while (swaps > 0 && i < n && j >= 0) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
                i++;
                j--;
                swaps--;
            } else {
                j--;
            }
        }

        // Recalculate beauty after rearrangement
        int beauty = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                beauty++;
            }
        }

        // If rearrangement successful, output the rearranged 'b' array
        if (beauty == x) {
            cout << "Rearranged 'b' array: ";
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Rearrangement not possible.\n";
        }
    }
    return 0;
}
