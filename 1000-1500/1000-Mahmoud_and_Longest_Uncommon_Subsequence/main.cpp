#include <cstdio>
#include <iostream>
using namespace std;

int main () {
	string f;
	string s;
	cin >> f >> s;
	if (f == s) {
		printf("%d\n", -1);
	} else {
		int ml = max(s.length(), f.length());
		printf("%d\n", ml);
	}
}
