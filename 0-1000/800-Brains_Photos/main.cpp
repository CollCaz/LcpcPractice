#include <iostream>
using namespace std;

int main() {
  int w, h;
  cin >> h >> w;
  bool colored = false;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char p;
      cin >> p;
      switch (p) {
      case 'C':
      case 'M':
      case 'Y':
        cout << "#Color" << endl;
        return 0;
      }
    }
  }
	cout << "#Black&White" << endl;
}
