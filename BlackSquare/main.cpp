#include <iostream>
#include <map>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  map<char, int> cals;
  cals['1'] = a;
  cals['2'] = b;
  cals['3'] = c;
  cals['4'] = d;

	string g;
	cin >> g;
	int sol = 0;
	for (char c : g) {
		sol += cals[c];
	}

	cout << sol << endl;
}
