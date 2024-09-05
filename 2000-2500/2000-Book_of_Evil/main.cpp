#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

int n, m, d;
unordered_set<int> affected;
map<int, unordered_set<int>> paths;

int dist(int a, int b, int dis) {
  if (a == b) {
    return 0;
  }
  if (dis == d) {
    int dd = dis;
    dd += 1;
    return dd;
  }
  if (paths[a].contains(b)) {
    int r = dis;
    dis = 1000000000;
    return r + 1;
  }
  for (int to : paths[a]) {
    int dd = dis;
    dd++;
    dist(to, b, dd);
  }
  return dis;
}

int sol = 0;
unordered_set<int> visted;
void s() {
  for (int i = 0; i < n - 1; i++) {

    if (affected.contains(i) || visted.contains(i)) {
      continue;
    }
    visted.insert(i);
    bool con = true;
    for (int at : affected) {
      cout << dist(at, i, 0) << endl;
      if (dist(at, i, 0) >= d) {
        con = false;
      }
    }
    if (con)
      sol++;
  }
}

int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    affected.insert(p);
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    paths[a].insert(b);
    paths[b].insert(a);
  }
  s();
  cout << sol << endl;
}
