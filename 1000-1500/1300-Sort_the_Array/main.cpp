#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> line;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    line.push_back(e);
  }
  int l = -1, r = -1;
  for (int i = 0; i < n - 1; i++) {
    if (l == -1 && line[i] > line[i + 1]) {
      l = i;
    }
    if (l != -1) {
      if (r == -1 && line[i] < line[i + 1]) {
        r = i;
      }
      if (r == -1 && i == n - 2) {
        r = i + 1;
      }
    }
  }
  // for (int i : line) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // cout << l + 1 << " " << r + 1 << endl;
  reverse(line.begin() + l, line.begin() + r + 1);
  // for (int i : line) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // cout << l + 1 << " " << r + 1 << endl;
  for (int i = 0; i < n - 1; i++) {
    if (line[i] >= line[i + 1]) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  if (l == -1) {
    l = 0;
  }
  if (r == -1) {
    r = 0;
  }
  cout << l + 1 << " " << r + 1;
}
