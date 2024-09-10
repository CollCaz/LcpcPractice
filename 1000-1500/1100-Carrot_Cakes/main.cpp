#include <iostream>
using namespace std;

int main() {
  int n, t, k, d;
	cin >> n >> t >> k >> d;
	int currt = 0;
	while (currt <= d) {
		n-= k;
		currt+=t;
	}

	if (n > 0) {
		cout << "YES" << endl;
	} else {
		printf("NO\n");
	}
}
