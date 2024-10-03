#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, k;
  bool bol = false;
  int div = 0;
  int count = 0;

  cin >> n >> k;
  int limit = ceil(n / 2.0) * ceil(n / 2.0) + floor(n / 2.0) * floor(n / 2.0);
  // cout << limit << endl;
  if (k > limit) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (count < k && ((bol && col % 2 != 0) || (!bol && col % 2 == 0))) {
        cout << "L";
        count++;
      } else {
        cout << "S";
      }
    }
    bol = !bol;
    cout << "\n";
  }
}
