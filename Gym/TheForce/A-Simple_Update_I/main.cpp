#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    string b;
    cin >> b;
    int c = 0;
    for (char ch : b) {
      if (ch == '1') {
        c++;
      }
    }
    cout << max<int>(c, (n - k)) << endl;
  }
}
