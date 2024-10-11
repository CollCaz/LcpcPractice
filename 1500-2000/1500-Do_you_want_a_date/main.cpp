#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int hacked[30000] = {0};
  long long n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> hacked[i];
  }
	sort(hacked, hacked + n);

	long long twoSum = 0;
	long long ans = 0;
	long long prev = 0;
}
