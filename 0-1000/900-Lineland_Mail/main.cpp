#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cities;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    cities.push_back(c);
  }
  int mi = 0;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      mi = (cities[i + 1] - cities[i]);
      ma = cities[n - 1] - cities[i];
      cout << mi << " " << ma << endl;
      continue;
    }
    if (i == n - 1) {
      mi = (cities[i] - cities[i - 1]);
      ma = cities[i] - cities[0];
      cout << mi << " " << ma << endl;
      continue;
    }
    mi = min((cities[i] - cities[i - 1]), (cities[i + 1] - cities[i]));
    ma = max((cities[i] - cities[0]), (cities[n - 1] - cities[i]));
    cout << mi << " " << ma << endl;
  }
}
