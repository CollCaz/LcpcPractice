#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  long long xs = x * 100;
  long long ys = y * 10;

  int step = -1;
  while (true) {
    step++;
    // Ciel
    if (step % 2 == 0) {
      if (xs >= 200 && ys >= 20) {
        xs -= 200;
        ys -= 20;
        continue;
      }
      if (xs >= 100 && ys >= 120) {
        xs -= 100;
        ys -= 120;
        continue;
      }
      if (ys >= 220) {
        ys -= 220;
        continue;
      }
      break;
    } else /*Hanako*/ {
      if (ys >= 220) {
        ys -= 220;
        continue;
      }
      if (ys >= 120 && xs >= 100) {
        ys -= 120;
        xs -= 100;
        continue;
      }
      if (ys >= 20 && xs >= 200) {
        ys -= 20;
        xs -= 200;
        continue;
      }
      break;
    }
  }
  if (step % 2 == 0) {
    cout << "Hanako" << endl;
  } else {
    cout << "Ciel" << endl;
  }
}
