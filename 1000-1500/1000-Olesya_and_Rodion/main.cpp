#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n, t;
  cin >> n >> t;
	if (n == 1 && t >= 10) {
		cout << -1 << endl;
	} else {
		int x = log10(t)+1;
		n = n-x;
		cout << t;
		while (n-- > 0) {
			cout << 0;
		}
	}
}
