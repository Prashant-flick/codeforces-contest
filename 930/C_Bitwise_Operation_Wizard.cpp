#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of permutation

        // Output queries and process responses
        for (int i = 0; i < 3 * n; i++) {
            int a, b, c, d;
            // Query indices a, b, c, d
            // Assuming you have some logic to determine these indices
            cout << "? " << a << " " << b << " " << c << " " << d << endl;
            cout.flush();

            char response;
            cin >> response; // Receive response

            // Process response accordingly
            // (pa∣pb)<(pc∣pd), (pa∣pb)=(pc∣pd), (pa∣pb)>(pc∣pd)

            // Ensure to break loop if pair i and j found
            // For example:
            // if (max_xor_value_found) {
            //     cout << "! " << i << " " << j << endl;
            //     cout.flush();
            //     break;
            // }
        }
    }

    return 0;
}