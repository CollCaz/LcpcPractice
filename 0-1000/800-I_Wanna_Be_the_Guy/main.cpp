#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> x;

  int xp, yp;
  cin >> xp;

  bool found = false;
  bool common = false;
  for (int i = 0; i < xp; i++) {
    int s;
    cin >> s;
    x.insert(s);
  }
  cin >> yp;
  for (int i = 0; i < yp; i++) {
    int s;
    cin >> s;
    x.insert(s);
  }
  cout << ((x.size() >= n) ? "I become the guy." : "Oh, my keyboard!") << endl;
}
