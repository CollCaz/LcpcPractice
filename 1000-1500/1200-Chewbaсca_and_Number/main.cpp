#include <iostream>
#include <string>
using namespace std;

int main() {
  string n;
  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    int num = (char)n[i] - '0';
    if (num > 4 && num > 0) {
      if (i != 0 || num < 9) {
        num = 9 - num;
      }
    }
    cout << num;
  }
  cout << endl;
}
