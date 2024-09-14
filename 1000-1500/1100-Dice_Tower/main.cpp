#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> possible;
typedef struct dice {
  int top = 0;
  int right = 0;
  int right_adj = 0;
  int left_adj = 0;
  int left = 0;
  int bottom = 0;
  void cal_bottom();
  possible pos_bottom();
} dice;

void dice::cal_bottom() { this->bottom = 7 - top; }

possible dice::pos_bottom() {
  possible p;
  for (int i = 1; i <= 6; i++) {
    if (i != this->right && i != this->left && i != this->right_adj &&
        i != this->left_adj) {
      p.push_back(i);
    }
  }

  return p;
}

int main() {
  int n, top;
  cin >> n >> top;
  dice topD;
  for (int i = 0; i < n; i++) {
    int left, right;
    cin >> left >> right;
    dice d;
    d.right = right;
    d.right_adj = 7 - d.right;
    d.left = left;
    d.left_adj = 7 - d.left;
    if (i == 0) {
      d.top = top;
      d.cal_bottom();
      topD = d;
    }
    int pos_found = 0;
    for (int side : d.pos_bottom()) {
      if (side != topD.bottom) {
        d.bottom = side;
        pos_found++;
      }
    }
    if (pos_found > 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
