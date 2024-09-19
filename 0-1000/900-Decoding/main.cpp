#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string mes;
  cin >> mes;
  string ogm = "";
  for (int i = 0; i < n; i++) {
    if (n % 2 != 0) {
      if (i % 2 != 0) {
        ogm.insert(0, 1, mes[i]);
      } else {
        ogm.push_back(mes[i]);
      }
    } else {
      if (i % 2 == 0) {
        ogm.insert(0, 1, mes[i]);
      } else {
        ogm.push_back(mes[i]);
      }
    }
  }
  cout << ogm << endl;
}
