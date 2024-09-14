#include <iostream>
using namespace std;

int main() {
  string scale, unused;
  cin >> scale >> unused;
  string rhss, lhss;
  int rhs = 0, lhs = 0;
  int *cur = &rhs;
  string *curs = &rhss;
  bool reached = false;
  for (int i = 0; i < scale.length(); i++) {

    if (scale[i] == '|') {
      reached = true;
      continue;
    }
    if (reached) {
      rhss += scale[i];
      rhs++;
    } else {
      lhss += scale[i];
      lhs++;
    }
  }
  while (unused.length() > 0) {
    if (rhs == lhs) {
      if (unused.length() % 2 != 0) {
        cout << "Impossible" << endl;
        return 0;
      } else {
        lhss += unused[unused.length() - 1];
        lhs++;
        unused.pop_back();
        rhss += unused[unused.length() - 1];
        rhs++;
        unused.pop_back();
      }
    } else if (rhs > lhs) {
      lhss += unused[unused.length() - 1];
      unused.pop_back();
      lhs++;
    } else {
      rhss += unused[unused.length() - 1];
      unused.pop_back();
      rhs++;
    }
  }
  if (rhs != lhs) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << lhss << "|" << rhss << endl;
}
