#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> before;
  vector<int> after;
  bool maybe = true;

  for (int i = 0; i < n; i++) {
    int b, a;
    cin >> b >> a;
    if (b != a) {
      cout << "rated";
      goto done;
    }
    before.push_back(b);
    after.push_back(a);
    if (i > 0) {
      if (before[i - 1] < b && after[i - 1] < a) {
        maybe = false;
      }
    }
  }
  cout << (maybe ? "maybe" : "unrated");
done:
  cout << endl;
}
