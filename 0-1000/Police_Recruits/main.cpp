#include <iostream>
using namespace std;

int main () {
	int p = 0;
	int c = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int oc;
		cin >> oc;

		if (oc > 0) {
			p+= oc;
		} else {
			if (p == 0) {
				c++;
			} else {
				p--;
			}
		}
	}

	cout << c << endl;
}
