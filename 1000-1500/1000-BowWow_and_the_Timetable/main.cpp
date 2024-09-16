#include <bitset>
#include <iostream>
using namespace std;

int main() {
  bitset<2 * 100> s;
  cin >> s;
  unsigned long long s_long = s.to_ulong();
  unsigned long long mins = 0b1;
  int c = 0;

  while (mins < s_long) {
    c++;
    mins <<= 4;
  }
  cout << c << endl;
}
