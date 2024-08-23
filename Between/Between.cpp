#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct node {
  int val = 0;
  vector<node *> adjacent;
};

string sol = "";
void recurs(node *nd) {
  if (nd->adjacent.empty()) {
    return;
  }
  for (auto adj : nd->adjacent) {
    sol = sol + " " + to_string(nd->val);
    cout << adj->val << endl;
    recurs(adj);
  }
}

int main() {
  int t;
  cin >> t;
  node *root = new node;
  root->val = 1;
  map<int, node *> nodes;
  for (int tc = 0; tc < t; tc++) {
    int n, m;
    cin >> n >> m;
    if (m == 0) {
      if (n > 1) {
        cout << "INFINITE" << endl;
        continue;
      }
      if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        continue;
      }
    }
    for (int p = 0; p < n; p++) {
      int a, b;
      cin >> a >> b;
      if (b == 1) {
        node *nd = new node;
        nd->val = a;
        root->adjacent.push_back(nd);
        nodes[a] = nd;
        continue;
      }
      node *nd = new node;
      nd->val = a;
      if (!nodes.contains(m)) {
        node *nd = new node;
        nd->val = b;
        nodes[b] = nd;
      }
      nodes[b]->adjacent.push_back(nd);
    }
    cout << "YES" << endl;
    recurs(root);
    cout << sol << endl;
  }
}
