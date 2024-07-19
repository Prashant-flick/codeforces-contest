#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    return result;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    

    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    int brr[n];
    int x = 1;

    for (int i=0; i<n ;i++) {
      int temp = gcd(x, arr[i]);
      temp = arr[i] / temp;
      x *= temp;
    }

    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += x / arr[i];
        brr[i]=x/arr[i];
    }

    if (sum >= x) {
        cout << -1 << endl;
    } else {

        for (int i=0; i<n; i++) {
            cout << brr[i] << " ";
        }
        cout << endl;
    }
  }
  return 0;
}