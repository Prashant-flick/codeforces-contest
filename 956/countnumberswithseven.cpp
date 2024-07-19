#include <iostream>
#include <vector>
#define MOD 1000000007
typedef long long ll;
using namespace std;

// Function to multiply two matrices
vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    int size = A.size();
    vector<vector<ll>> C(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Function to perform matrix exponentiation
vector<vector<ll>> matrixPower(vector<vector<ll>> base, ll exp) {
    int size = base.size();
    vector<vector<ll>> result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++) {
        result[i][i] = 1;  // Identity matrix
    }
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

int countWays(ll n) {
    if (n == 0) return 1;

    // Define the transformation matrix based on the recurrence relation
    vector<vector<ll>> transform = {
        {10, 1},  // [sum] = 10 * [sum_prev] + [prev_prev]
        {0, 1}    // [prev] = [sum_prev]
    };

    // Apply matrix exponentiation
    vector<vector<ll>> result = matrixPower(transform, n - 1);

    // Initial state vector
    ll sum = 1;   // sum_1
    ll prev = 0;  // prev_1

    // Calculate final result
    ll finalSum = (result[0][0] * sum + result[0][1] * prev) % MOD;
    return (finalSum - prev + MOD) % MOD;
}

int main() {
    ll n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}
