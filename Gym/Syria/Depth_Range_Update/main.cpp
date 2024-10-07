#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef map<int, vector<int>> graph;
typedef map<int, vector<int>> depths;

void dfs(graph &g, const int &node, const int &depth, depths &ds,
         set<int> &visited) {
  if (visited.count(node) != 0) {
    return;
  }
  visited.insert(node);
  ds[depth].emplace_back(node);
  for (int adj : g[node]) {
    dfs(g, adj, depth + 1, ds, visited);
  }
}

void xorPath(int u, int node, graph &g, int prev, vector<int> &values,
             vector<int> &xorVals, set<int> &visited) {
  if (visited.count(node) != 0) {
    return;
  }
  visited.insert(node);
  if (node != u) {
    xorVals[node] = values[node - 1] ^ prev;
  }
  cout << "node: " << node << ": " << xorVals[node] << endl;
  for (int adj : g[node]) {
    xorPath(u, adj, g, values[node - 1], values, xorVals, visited);
  }
}

void q1(int l, int r, int x, depths &ds, vector<int> &values) {
  values[l - 1] ^= x;
  values[r - 1] ^= x;
}

void q2(int u, graph &g, vector<int> &values) {
  vector<int> xorVals(g.size() + 2, 0);
  xorVals[u] = 0;
  xorPath(u, u, g, 0, values, xorVals, *new set<int>);
  int s = 0;
  for (int i : xorVals) {
    s += i;
  }
  cout << endl;
  cout << s << endl;
}

void solve() {
  int n, q;
  cin >> n >> q;
  graph g;
  vector<int> values;
  depths ds;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    values.push_back(v);
  }

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(g, 1, 0, ds, *new set<int>);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      // for (int v : values) {
      //   cout << v << " ";
      // }
      // cout << endl;
      q1(l, r, x, ds, values);
      // for (int v : values) {
      //   cout << v << " ";
      // }
      // cout << endl;
    } else {
      int u;
      cin >> u;
      q2(u, g, values);
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
