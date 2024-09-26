#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_SIZE = 1e5 + 1;
unsigned long long v[MAX_SIZE];
unsigned long long vs[MAX_SIZE];

unsigned long long inline q(unsigned long long v[], int l, int r) {
  return v[r] - v[l - 1];
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    unsigned long long c;
    cin >> c;
    v[i] = vs[i] = c;
  }
  sort(vs + 1, vs + n + 1);

  for (int i = 1; i <= n; i++) {
    v[i] = v[i] + v[i - 1];
    vs[i] = vs[i] + vs[i - 1];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      cout << q(v, l, r) << endl;
    } else {
      cout << q(vs, l, r) << endl;
    }
  }
}
