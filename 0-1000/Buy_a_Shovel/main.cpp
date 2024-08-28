#include <iostream>
using namespace std;

int main () {
	int t = 1;
	int p, c;
	cin >> p >> c;

	while (true) {
		if ((p * t) % 10 == c || (p * t) % 10 == 0) {
			break;
		}
		t++;
	}

	cout << t << endl;
}
