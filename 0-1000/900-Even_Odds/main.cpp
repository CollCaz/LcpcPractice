#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long n;
  long long k;
  cin >> n >> k;
  long long cut = ceil((double)n / 2.f);
  // if (n % 2 == 1) {
  //   cut++;
  // }
  if (k <= cut) {
    cout << (k * 2 - 1);
  } else {
    cout << (k - cut) * 2;
  }
}
