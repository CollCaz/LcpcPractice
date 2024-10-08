#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string b;
    cin >> b;

    int c = count(b.begin(), b.end(), '1');
    int fz = b.find('0');
    int lz = b.rfind('0');

    for (int k = 1; k <= n / 2; k++) {
      if (c >= n - k) {
        cout << 0 << " ";
      } else {
        cout << (lz - fz) / k << " ";
      }
    }
    cout << endl;
  }
}
