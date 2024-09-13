#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  long double n, m, a;
  cin >> n >> m >> a;
  long long ans = (long long)ceil(n / a) * ceil(m / a);
	printf("%lld", ans);
}
