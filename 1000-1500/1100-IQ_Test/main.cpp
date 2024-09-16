#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> test;
  for (int i = 0; i < 4; i++) {
    string row;
		cin >> row;
    test.push_back(row);
  }
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      int sum = 0;
      if (test[x][y] == '#') {
        sum++;
      }
      if (test[x][y + 1] == '#') {
        sum++;
      }
      if (test[x + 1][y] == '#') {
        sum++;
      }
      if (test[x + 1][y + 1] == '#') {
        sum++;
      }
      if (sum <= 1 || sum >= 3) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
	cout << "NO" << endl;
}
