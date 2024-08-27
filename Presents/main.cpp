#include <iostream>
#include <map>
using namespace std;

int main () {
	int n;
	cin >> n;
	map<int, int> gifts;
	for (int i = 1; i <= n; i++) {
		int g;
		cin >> g;
		gifts[g] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << gifts[i] << " ";
	}
	cout << "\n";
}
