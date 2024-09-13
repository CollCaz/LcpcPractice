#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> paper;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    paper.push_back(row);
  }

  char other = paper[0][1];
  char dig = paper[0][0];
  if (other == dig) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0 + i || j == (n - 1) - i) {
        if (paper[i][j] != dig) {
          cout << "NO" << endl;
          return 0;
        }
      } else if (paper[i][j] != other) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
