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
    int c = 0;
    int fz = -1;
    int lz = -1;
    for (int i = 0; i < b.length(); i++) {
      if (b[i] == '1')
        c++;
      if (fz == -1 && b[i] == '0')
        fz = i;
      if (b[i] == '0')
        lz = i;
    }
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
