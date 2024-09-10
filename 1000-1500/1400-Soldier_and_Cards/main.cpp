#include <deque>
#include <iostream>
#include <set>
using namespace std;

int n;
deque<int> one;
deque<int> ogone;
deque<int> two;
deque<int> ogtwo;

enum winners {
  NONE,
  ONE,
  TWO,
};

struct sol {
  winners w;
  int c;
};

typedef pair<int, int> cardPair;
set<cardPair> compared;

sol solve(int onec, int twoc, int c) {
  if (one.size() == 0 || two.size() == 0) {
    return sol{(one.size() == 0) ? TWO : ONE, c};
  }
  cardPair thisPair = cardPair(onec, twoc);
  if (compared.count(thisPair) > 0) {
    return sol{NONE, -100};
  }
  compared.insert(thisPair);
  one.pop_front();
  two.pop_front();
  if (onec > twoc) {
    one.push_back(twoc);
    one.push_back(onec);
  } else {
    two.push_back(onec);
    two.push_back(twoc);
  }
  return solve(one.front(), two.front(), ++c);
}

int main() {
  cin >> n;
  for (int i = 0; i < 2; i++) {
    int nc;
    cin >> nc;
    for (int j = 0; j < nc; j++) {
      int c;
      cin >> c;
      if (i == 0) {
        one.push_back(c);
      } else {
        two.push_back(c);
      }
    }
  }
	ogone = one;
	ogtwo = two;
  sol solution = solve(one.front(), two.front(), 0);
  if (solution.w == NONE) {
    cout << -1 << endl;
  } else {
    cout << solution.c << " " << solution.w << endl;
  }
}
