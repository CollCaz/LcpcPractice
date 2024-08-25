#include <iostream>
#include <vector>
using namespace std;

int main () {
	int n, b, d;
	cin >> n >> b >> d;
	vector<int> oranges;
	int w = 0;
	int c = 0;
	for (int i = 0; i < n; i++) {
		int o;
		cin >> o;
		if (o <= b) {
			c += o;
		}
		if (c > d) {
			++w;
			c = 0;
		}
	}
	cout << w << "\n";
}
