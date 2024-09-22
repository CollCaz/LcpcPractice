#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, a, d;
    cin >> n >> m >> a >> d;
    int count = 0;
    for (int j = n; j <= m; j++) {
      if (j % a == 0) {
        continue;
      }
      // if (j % (a + 4 * d) == 0) {
      //   continue;
      // }
      if (j % (a + 2 * d) == 0) {
        continue;
      }
      if (j % (a + 3 * d) == 0) {
        continue;
      }
      if (j % (a + d) == 0) {
        continue;
      }
      count++;
    }
    cout << count << endl;
    count = 0;
  }
}
