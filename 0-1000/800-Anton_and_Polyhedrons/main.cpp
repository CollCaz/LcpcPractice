#include <iostream>
#include <map>
using namespace std;

int main () {
	int n;
	int ans = 0;
	cin >> n;
	map<string, int> sides = {
		{"Tetrahedron",  4},
		{"Cube", 6},
		{"Octahedron", 8},
		{"Dodecahedron", 12},
		{"Icosahedron", 20}
	};
	for (int i = 0; i < n; i++) {
		string hedron;
		cin >> hedron;
		ans += sides[hedron];
	}
	cout << ans << endl;
}
