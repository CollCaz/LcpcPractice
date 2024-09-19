#include <iostream>
#include <map>
using namespace std;

int main () {
	int n;
	cin >> n;
	map<int, int> idx;
	for (int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		idx[ai] = i;
	}
	long long m;
	cin >> m;
	long long v = 0, p = 0;
	for (int i = 0; i < m; i++) {
		int lf;
		cin >> lf;
		v += idx[lf]+1;
		p += n - idx[lf];
	}
	cout << v << " " << p << endl;

}
