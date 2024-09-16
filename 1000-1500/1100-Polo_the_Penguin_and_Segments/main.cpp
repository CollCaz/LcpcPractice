#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int sum = 0;
  int moves = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    int total = ((r - l) + 1);
    sum += total;
  }
  // while (sum % k != 0) {
  //   sum++;
  //   moves++;
  // }
  cout << ((k - (sum % k)) % k) << endl;
}
