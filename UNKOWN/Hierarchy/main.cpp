#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> demands;
map<int, int> parents;

void makeParentOf(int sup, int inf) {
  if (parents[inf] == 0) {
    parents[inf] = sup;
    return;
  }
  makeParentOf(sup, parents[inf]);
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    parents[i] = 0;
    int w;
    cin >> w;
    for (int j = 0; j < w; j++) {
      int b;
      cin >> b;
      demands[i].push_back(b);
    }
  }
  for (pair<int, vector<int>> demand : demands) {
    for (int inf : demand.second) {
      makeParentOf(demand.first, inf);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << parents[i] << endl;
  }
}
