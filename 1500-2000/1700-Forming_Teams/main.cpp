#include <iostream>
#include <map>
#include <vector>
using namespace std;

enum colors {
  NONE,
  RED,
  GREEN,
  REMOVED,
};
typedef int node;

map<node, vector<node>> confs;
map<node, colors> colorOfNodes;

int removedCount = 0;

void colorNode(node n) {
  bool greenFound = false;
  bool redFound = false;
  if (colorOfNodes[n] != NONE) {
    return;
  }
  for (node adj : confs[n]) {
    greenFound = (greenFound || colorOfNodes[adj] == GREEN);
    redFound = (redFound || colorOfNodes[adj] == RED);
  }
  if (!redFound) {
    colorOfNodes[n] = RED;
  } else if (!greenFound) {
    colorOfNodes[n] = GREEN;
  } else {
    colorOfNodes[n] = REMOVED;
    removedCount++;
  }
}

int main() {
  int n, np;
  cin >> n >> np;
  for (int i = 0; i < np; i++) {
    node a, e;
    cin >> a >> e;
    confs[a].push_back(e);
    confs[e].push_back(a);
  }
  for (pair<node, vector<node>> kv : confs) {
    colorNode(kv.first);
  }
  if ((n - removedCount) % 2 != 0){
    removedCount++;
  }
  cout << removedCount << endl;
}
