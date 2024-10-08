#include <iostream>
using namespace std;

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      cout << factorial(n-1) * 2 << endl;
    }
  }
}
