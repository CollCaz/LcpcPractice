#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

string factorial(char num) {
	switch (num) {
		case '0':
		return "";
		case '1':
		return "";
		case '2':
		return "2";
		case '3':
		return "3";
		case '4':
		return "322";
		case '5':
		return "5";
		case '6':
		return "53";
		case '7':
		return "7";
		case '8':
		return "7222";
		case '9':
		return "7332";
	}
	return "";
}

int main() {
  int n;
	string a;
  cin >> n >> a;
	int ans = 0;
	string anss;
	for (char c : a) {
		string fac = factorial(c);
		anss += fac;
	}
	sort(anss.begin(), anss.end(), greater<>());
	cout << anss << endl;
}
