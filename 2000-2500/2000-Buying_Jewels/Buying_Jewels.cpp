#include <iostream>
using namespace std;

int main() {
  long long t;
  cin >> t;
  for (long long tc = 0; tc < t; tc++) {
    long long n, k;
    cin >> n >> k;
    if (n < k) {
      cout << "NO" << endl;
      continue;
    }
    if (n == k) {
      cout << "YES" << endl;
      cout << 1 << endl;
      cout << 1 << endl;
      continue;
    }
    if (n > k && (k * 2) > (n + 1)) {
      cout << "NO" << endl;
    } else {
      long long p1 = n - k + 1;
      long long p2 = 1;
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << p1 << " " << p2 << endl;
    }

  }
}
