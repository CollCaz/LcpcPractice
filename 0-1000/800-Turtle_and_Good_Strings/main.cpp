#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l;
    string s;
    cin >> l;
		cin >> s;
    if (s[0] != s[s.length() - 1]) {
      cout << "YES" << endl;
    } else {
			cout << "NO" << endl;
		}
  }
}
