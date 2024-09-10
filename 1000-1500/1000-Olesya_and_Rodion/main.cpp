#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  if (n == 1) {
    if (t < 10) {
      cout << t << endl;
      return 0;
    } else {
      cout << "-1" << endl;
      return 0;
    }
  }
  if (to_string(t).length() > n) {
    cout << "-1.2" << endl;
    return 0;
  }
}
