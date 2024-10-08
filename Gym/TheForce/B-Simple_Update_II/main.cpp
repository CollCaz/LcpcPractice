#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int countOnes = count(s.begin(), s.end(), '1');
    int firstZeroIndex = s.find('0');
    int lastZeroIndex = s.rfind('0');

    for (int k = 1; k <= n / 2; k++) {
      if (countOnes >= n - k) {
        cout << 0 << " ";
      } else {
        cout << (lastZeroIndex - firstZeroIndex) / k << " ";
      }
    }
    cout << endl;
  }
}
