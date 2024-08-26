#include <cmath>
#include <iostream>
using namespace std;

int main() {
  unsigned int t;
  while (cin >> t && t != 0) {
		unsigned int sq = (int)sqrt(t);
		cout << (sq * sq == t ? "yes\n": "no\n");
  }
}
