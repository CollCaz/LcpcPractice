#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  long long dis = 0;
	long long ice = x;
  for (int i = 0; i < n; i++) {
		char pn;
		long d;
		cin >> pn >> d;
		if (pn == '+') {
			ice += d;
		} else {
			if (ice >= d) {
				ice -= d;
			} else {
				dis++;
			}
		}
  }

	printf("%lld %lld\n", ice, dis);
}
