#include <algorithm>
#include <iostream>
using namespace std;

int main () {
	string n;
	cin >> n;
	cout << n;
	reverse(n.begin(), n.end());
	cout << n;
}
