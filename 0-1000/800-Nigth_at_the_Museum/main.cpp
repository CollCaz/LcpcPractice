#include <iostream>
using namespace std;

int main () {
	int d = 0;
	string n;
	cin >> n;
	char p = 'a';

	for (char c : n) {
		if (abs(p - c) <= 13) {
			d += (int)abs(p - c);
		} else {
			d += (int)abs(26 - abs(p-c));
		}
		p = c;
	}

	cout << d << endl;
}
