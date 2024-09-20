#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct segment {
  int x;
  int y;

  segment(int xv, int yv) : x(xv), y(yv) {}
} segment;

long double length(const segment &f, const segment &s) {
  int a = abs(f.x - s.x);
  int b = abs(f.y - s.y);
  long double c = pow(a, 2) + pow(b, 2);

  return sqrt(c);
}

int main() {
  vector<segment> segments;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    segment s(x, y);
    segments.push_back(s);
  }
  long double all_dist = 0;
  for (int i = 0; i < segments.size()-1; i++) {
    all_dist += length(segments[i], segments[i + 1]);
  }
  long double ans = all_dist / 50.0;
  printf("%Lf\n", ans * k);
}
