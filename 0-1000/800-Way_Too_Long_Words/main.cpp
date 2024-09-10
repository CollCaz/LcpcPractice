#include <iostream>
#include <string>
using namespace std;

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string w;
		string nw = "";
		cin >> w;
		if (w.length() > 10) {
			nw += w[0];
			nw += to_string(w.length()-2);
			nw += w[w.length()-1];
		} else {
			nw = w;
		}
		cout << nw << "\n";
	}
}
