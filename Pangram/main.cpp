#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  int n;
  string ans = "YES";
  set<char> found;
  cin >> n;
  if (n < 26) {
    ans = "NO";
  } else {
    string ss;
    cin >> ss;
    for (char c : ss) {
			found.insert(tolower(c));
    }
  }
  cout << ((found.size() == 26) ? "YES" : "NO") << endl;
}
