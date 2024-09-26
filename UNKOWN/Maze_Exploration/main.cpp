#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_LINES = 30;
const int MAX_CHARS = 80;

vector<string> lines;
pair<int, int> start;

void explore(int x, int y) {
  lines[x][y] = '#';
  if (lines[x + 1][y] == ' ') {
    lines[x + 1][y] = '#';
    explore(x + 1, y);
  }
  if (lines[x - 1][y] == ' ') {
    lines[x - 1][y] = '#';
    explore(x - 1, y);
  }
  if (lines[x][y + 1] == ' ') {
    lines[x][y + 1] = '#';
    explore(x, y + 1);
  }
  if (lines[x][y - 1] == ' ') {
    lines[x][y - 1] = '#';
    explore(x, y - 1);
  }
}

int main() {
  int n;
  cin >> n;
  string line;
  for (int i = 0; i < n; i++) {
    lines.clear();
    while (getline(cin, line) && line[0] != '_') {
      lines.push_back(line);
    }
    int x, y;
    for (int i = 0; i < lines.size(); i++) {
      for (int j = 0; j < lines[i].size(); j++) {
        if (lines[i][j] == '*') {
          x = i;
          y = j;
          goto next;
        }
      }
    }
  next:
    explore(x, y);
    for (auto l : lines) {
      if (!l.empty())
        cout << l << endl;
    }
    if (!line.empty())
      cout << line << endl;
  }
}
