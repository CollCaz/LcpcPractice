#include <iostream>
#include <string>
#include <variant>
using namespace std;

int main() {
  int n, k;
	int ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    bool allFound = true;
    string line;
    cin >> line;
    for (int i = 0; i <= k; i++) {
      if (line.find(to_string(i)) == variant_npos) {
        allFound = false;
      }
    }
    if (allFound) {
      ans++;
    }
  }
  cout << ans << endl;
}
