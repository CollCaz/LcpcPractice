#include <bitset>
#include <iostream>
using namespace std;

int main () {
	int x;
	cin >> x;
	bitset<10*9> bs = x;
	cout << bs.count() << endl;
}
