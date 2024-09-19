#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct box {
  int amount;
  int matches;
} box;

bool compBoxes(const box &a, const box &b) { return a.matches > b.matches; }

int main() {
  unsigned long long n;
  int m;
  cin >> n >> m;
  vector<box> boxes;
  for (int i = 0; i < m; i++) {
    box b;
    int a, nm;
    cin >> a >> nm;
    b.amount = a;
    b.matches = nm;
    boxes.push_back(b);
  }
  sort(boxes.begin(), boxes.end(), compBoxes);
  int took = 0;
  unsigned long long ans = 0;
  for (box b : boxes) {
    if (b.amount == 0) {
      continue;
    }
    while (b.amount > 0 && took < n) {
			b.amount--;
			took++;
			ans += b.matches;
    }
  }
	printf("%llu\n", ans);
}
