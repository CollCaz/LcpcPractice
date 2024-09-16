#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string steps;
  cin >> steps;
  int s = 0, t = 0;
  for (int i = 0; i < steps.length() - 1; i++) {
    if (s == 0 && steps[i] != '.') {
      s = i + 1;
      if (steps[i] == 'L') {
        t = i;
        break;
      }
    }
    if (steps[i] != '.' && steps[i] != steps[i + 1]) {
      if (steps[i + 1] == '.') {
        t = i + 2;
      } else {
        t = i + 1;
      }
      break;
    }
  }
  cout << s << " " << t;
}
