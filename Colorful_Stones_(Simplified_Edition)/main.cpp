#include <iostream>
using namespace std;

int main() {
  string colors, inst;
  cin >> colors >> inst;

  int c = 0;
  int i = 0;

  int steps = 1;
  while (c < colors.length()) {
		if (i == inst.length()) {
			break;
		}
    while (i < inst.length()) {
      if (colors[c] == inst[i]) {
        c++;
        steps++;
      }
      i++;
    }
  }

  cout << steps << endl;
}
