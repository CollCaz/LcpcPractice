#include <iostream>
using namespace std;

int main() {
  string kb = "qwertyuiopasdfghjkl;zxcvbnm,./";
  char d;
  cin >> d;
  string m;
  cin >> m;
  for (char c : m) {
    for (int i = 0; i < kb.length(); i++) {
      if (kb[i] == c) {
        if (d == 'R') {
          cout << kb[i - 1];
        } else {
          cout << kb[i + 1];
        }
      }
    }
  }
	cout << endl;
}
