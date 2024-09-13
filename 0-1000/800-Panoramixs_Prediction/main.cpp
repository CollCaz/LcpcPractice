#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n % 2 == 0) {
    return false;
  }
  for (int i = 3; i < n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  if (m % 2 == 0 && m != 2) {
    cout << "NO" << endl;
    return 0;
  }

  if (!isPrime(m)) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = n + 1; i < m; i++) {
    if (isPrime(i)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
