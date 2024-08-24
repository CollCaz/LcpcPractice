#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> home;
	vector<int> guest;
	for (int i = 0; i < n; i++) {
		int h, g;
		cin >> h >> g;
		home.push_back(h);
		guest.push_back(g);
	}

	int sol = 0;
	for (int h : home) {
		sol += count(guest.begin(), guest.end(), h);
	}
	cout << sol << endl;
}
