#include <iostream>
#include <set>
using namespace std;

int main () {
	set<char> s;
	while (true) {
		char c;
		cin >> c;
		if (c == '}') {
			break;
		}
		if (c != '{' && c != ' ' && c != ',') {
			s.insert(c);
		}
	}

	cout << s.size() << endl;
}
