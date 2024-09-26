#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> input;
vector<input> fence;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n + k; i++) {
    if (i < n) {
      int p;
      cin >> p;
      fence.push_back(input(p, i + 1));
    } else {
      fence.push_back(input(0, i + 1));
    }
  }
  vector<input> fence2 = fence;
  for (int i = n; i >= 0; i--) {
    fence[i].first += fence[i + 1].first;
    fence2[i].first = fence[i].first;
    fence2[i].first -= fence[i + k].first;
  }
  sort(fence2.begin(), fence2.end() - (k + (k - 1)),
       [](const input &a, const input &b) { return a.first < b.first; });
  cout << fence2[0].second << endl;
}

