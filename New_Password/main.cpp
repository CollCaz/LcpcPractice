#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  char last;
  for (int i = 0; i < n; i++) {
    if (i <= k-1) {
      cout << (char)('a' + i);
    } else {
      char n = (i % 2 == 0) ? 'a' : 'b';
      cout << n;
    }
  }
  cout << "\n";
}
