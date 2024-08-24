#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> birds;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    birds.push_back(b);
  }
  int s;
  cin >> s;
  for (int i = 0; i < s; i++) {
    int x, y;
    cin >> x >> y;
    int ix = x - 1;
    int iy = y - 1;

    int down = y - 1;
    int up = birds[ix] - y;
    int all = down + up + 1;
    birds[ix] -= all;
    if (ix > 0) {
      birds[ix - 1] += down;
    }
    if (ix < n) {
      birds[ix + 1] += up;
    }
  }

  for (int l : birds) {
    cout << l << endl;
  }
}
