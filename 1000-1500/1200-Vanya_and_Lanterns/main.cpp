#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;

  vector<int> lanterns;

  for (int i = 0; i < n; i++) {
    int lp;
    cin >> lp;
    lanterns.push_back(lp);
  }
  if (n == 1) {
    long double ans;
    ans = max((lanterns[0]), (l - lanterns[0]));
    cout << ans << endl;
		return 0;
  }

  sort(lanterns.begin(), lanterns.end(), less<>());

  vector<long double> distances;
  for (int i = 0; i < lanterns.size(); i++) {
    long double dist = 0;
    if (i == 0) {
      if (lanterns[0] != 0) {
        dist = lanterns[0];
        distances.push_back(dist);
      }
      dist = (lanterns[1] - lanterns[0]) / 2.0;
      distances.push_back(dist);
      continue;
    }
    if (i == lanterns.size() - 1) {
      if (lanterns[i] != l) {
        dist = l - lanterns[i];
        distances.push_back(dist);
      }
      continue;
    }

    dist = (lanterns[i + 1] - lanterns[i]) / 2.0;
    distances.push_back(dist);
  }
  long double m = *max_element(distances.begin(), distances.end());
  printf("%Lf\n", m);
}
