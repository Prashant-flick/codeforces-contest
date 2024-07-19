#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long brr[31];
    brr[0] = 1;
    for (int i = 1; i < 31; i++) {
        brr[i] = brr[i - 1] * 2;
    }

    while (t--) {
        int n, q;
        cin >> n >> q;
        long long arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int xrr[q];
        for (int i = 0; i < q; i++) {
            cin >> xrr[i];
        }

        for (int j = 0; j < n; j++) {
            if (arr[j] % 2 == 0) { // Check if the number is even
                for (int i = 0; i < q; i++) {
                    if (arr[j] % brr[xrr[i]] == 0) {
                        arr[j] += brr[xrr[i] - 1];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
