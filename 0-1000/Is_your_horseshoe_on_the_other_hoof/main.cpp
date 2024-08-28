#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main () {
	vector<int> v;
	set<int> s;
	for (int i = 0; i < 4; i++) {
		int c;
		cin >> c;
		v.push_back(c);
		s.insert(c);
	}

	cout << (v.size() - s.size()) << endl;
}
