#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, ep;
enum color {
  NONE,
  RED,
  GREEN,
  OUT,
};

map<int, vector<int>> confs;
map<int, color> colors;

int removed = 0;
int staying = 0;

int main() {
  cin >> n >> ep;
  for (int i = 0; i < n; i++) {
    confs[i] = vector<int>();
    colors[i] = NONE;
  }
  for (int i = 0; i < ep; i++) {
    int p, e;
    cin >> p >> e;
    confs[p].push_back(e);
    confs[e].push_back(p);
  }

  for (int i = 1; i <= n; i++) {
    staying++;
    if (colors[i] != NONE) {
      continue;
    }
    bool redFound = false;
    bool greenFound = false;
    for (int conf : confs[i]) {
      redFound = redFound || (colors[conf] == RED);
      greenFound = greenFound || (colors[conf] == GREEN);
    }
    if (!redFound) {
      colors[i] = RED;
    } else if (!greenFound) {
      colors[i] = GREEN;
    } else {
      colors[i] = OUT;
      removed++;
      staying--;
    }
  }
  if ((staying) % 2 != 0) {
    removed++;
  }
  cout << removed << endl;
}
