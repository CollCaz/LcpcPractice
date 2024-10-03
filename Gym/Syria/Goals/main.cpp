#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int m = 0;
  long long sum = 0;
  for (long i = 0; i < n; i++) {
    int c;
    cin >> c;
    m = max(m, c);
    sum += c;
  }
  printf("%lld %lld\n", max<long long int>(m, ceil(sum / 2.0)), sum);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
