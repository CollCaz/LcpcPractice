#include <iostream>
#include <set>
#include <vector>
using namespace std;

int x = 0, y = 0;
vector<vector<char>> maze;
set<char> word = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
set<pair<int, int>> visited;

void path(int idx, int idy, string p) {
  if (maze[idx][idy] == '#') {
		p[p.length()-1] = '\0';
    cout << p << endl;
    // return p;
  }
  pair<int, int> tp = pair<int, int>(idx, idy);
  visited.insert(tp);

  if (idx > 0) {
    pair<int, int> above = pair<int, int>(idx - 1, idy);
    if (visited.count(above) == 0 &&
        word.count(maze[above.first][above.second]) > 0) {
      string np = p + "forth ";
      path(above.first, above.second, np);
    }
  }
  if (idy < y-1) {
    pair<int, int> right = pair<int, int>(idx, idy + 1);
    if (visited.count(right) == 0 &&
        word.count(maze[right.first][right.second]) > 0) {
      string np = p + "right ";
      path(right.first, right.second, np);
    }
  }
  if (idy > 0) {
    pair<int, int> left = pair<int, int>(idx, idy - 1);
    if (visited.count(left) == 0 &&
        word.count(maze[left.first][left.second]) > 0) {
      string np = p + "left ";
      path(left.first, left.second, np);
    }
  }

  return;
}

void solve() {
	x = y = 0;
  cin >> x >> y;
  int sx, sy;
  maze.clear();
  visited.clear();
  maze.resize(x);
  for (int i = 0; i < x; i++) {
    vector<vector<char>> v;
    for (int j = 0; j < y; j++) {
      char s;
      cin >> s;
      maze[i].push_back(s);
      if (s == '@') {
        sx = i;
        sy = j;
      }
    }
  }
  path(sx, sy, "");
}

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    n--;
    solve();
  }
}
