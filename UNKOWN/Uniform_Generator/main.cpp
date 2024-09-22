#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void solve(long long s, long long m) {
  cout << setw(10) << s << " " << setw(9) << m;
  if (gcd(s, m) == 1) {
    cout << setw(15) << right << "Good Choice";
  } else {
    cout << setw(14) << right << "Bad Choice";
  }
  cout << endl << endl;
}

int main() {
  long long s, m;
  // for (int i = 1; i <= 30; i++) {
  //   if (i == 10 || i == 20 || i == 25) {
  //     cout << "x";
  //   } else {
  // 	cout << ".";
  // }
  // }
  // cout << endl;
  while (cin >> s >> m) {
    solve(s, m);
  }
}
