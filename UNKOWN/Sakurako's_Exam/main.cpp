#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
		a %= 2;
		if ((a + (2*b)) % 2 != 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
  }
}
