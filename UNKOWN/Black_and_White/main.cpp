#include <cstdio>
#include <iostream>
using namespace std;


int main() {
  int n, m, c;
  while (cin >> n >> m >> c && n != 0) {
    printf("%d\n", ((n - 7) * (m - 7) + c) / 2);
  }
}
