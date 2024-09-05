#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<set<int>> conf;
map<int, int> color;

int discarded = 0;

int main() {
  cin >> n >> m;
  conf.resize(n * 2);
  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    conf[s].insert(e);
    conf[e].insert(s);
  }
  vector<int> red;
  vector<int> green;
  set<int> visited;

  for (int i = 1; i <= n; i++) {
    int s = (red.size() >= green.size()) ? 1 : 2;
    // 01 xor 11 = 10
    // 10 xor 11 = 01
    int l = s ^ 3;
    int acc_col = 0;
    for (int c : conf[i]) {
      acc_col += color[c];
    }
    if (acc_col == 0) {
      color[i] = s;
    }
    if (acc_col == 1) {
      color[i] = 2;
    } else {
      color[i] = 0;
    }
  }
  discarded += ((n - discarded) % 2 == 0) ? 0 : 1;
  cout << discarded << endl;
}
