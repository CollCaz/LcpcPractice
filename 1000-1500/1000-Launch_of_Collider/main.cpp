#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n;
  string dir;
  cin >> n >> dir;
  vector<int> points;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    points.push_back(p);
  }
  int ans = (int)INFINITY;
  for (int i = 0; i < n - 1; i++) {
    if (dir[i] == 'R') {
      if (dir[i + 1] == 'L') {
        int dis = (points[i + 1] - points[i]);
        ans = min(ans, dis);
      }
    }
    if (dir[i] == 'L') {
      if (i > 0 && dir[i - 1] == 'R') {
        int dis = (points[i] - points[i - 1]);
				ans = min(ans, dis);
      }
    }
  }
	long long actual_answer = ((ans == (int)INFINITY) ? -1 : ceil((double)ans / 2.0));
	printf("%lld", actual_answer);
}
