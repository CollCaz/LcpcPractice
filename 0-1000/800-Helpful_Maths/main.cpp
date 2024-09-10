#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<char> sums;
  for (char c : s) {
    if (c != '+')
      sums.push_back(c);
  }
  sort(sums.begin(), sums.end());
  bool a = false;
  for (char c : sums) {
    if (a)
      cout << "+" << c;
    else {
      cout << c;
      a = true;
    }
  }
  cout << endl;
}
