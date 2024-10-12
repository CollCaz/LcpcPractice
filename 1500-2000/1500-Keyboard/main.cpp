#include <cctype>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct point {
  int x = -1;
  int y = -1;
};

double dist(point a, point b) {
  return sqrt((pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

int main() {
  int n, m, maxd;
  cin >> n >> m >> maxd;
  // cout << dist(point{0, 1}, point{1, 1}) << endl;
  vector<vector<int>> keyboard;
  vector<point> shifts;
  map<char, point> keyPoints;
  keyboard.reserve(n);
  for (int i = 0; i < n; i++) {
    keyboard[i].reserve(m);
    for (int j = 0; j < m; j++) {
      char key;
      cin >> key;
      if (key == 'S') {
        shifts.push_back(point{i, j});
      }
      keyPoints[key] = point{i, j};
      keyboard.emplace_back(key);
    }
  }

  bool noShifts = false;
  if (shifts.size() == 0) {
    noShifts = true;
  }

  int q;
  cin >> q;
  string t;
  cin >> t;
  int sol = 0;
  for (int i = 0; i < q; i++) {
    if (keyPoints[tolower(t[i])].x == -1) {
      cout << -1 << endl;
      return 0;
    }
    if (!islower(t[i])) {
      if (noShifts) {
        cout << -1 << endl;
        return 0;
      }
      // cout << t[i] << endl;
      // cout << keyPoints[tolower(t[i])].x << " ";
      // cout << keyPoints[tolower(t[i])].y << endl;
      bool yes = false;
      for (point s : shifts) {
        // cout << s.x << " ";
        // cout << s.y << endl;
        // cout << dist(keyPoints[tolower(t[i])], s) << endl;
        if (dist(s, keyPoints[tolower(t[i])]) <= maxd) {
          // cout << t[i] << endl;
          yes = true;
          break;
        }
      }
      if (!yes) {
        sol++;
      }
    }
  }
  cout << sol << endl;
}
