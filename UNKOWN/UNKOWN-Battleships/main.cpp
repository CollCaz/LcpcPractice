#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> grid;
void zeroConnected(int x, int y) {
  if (x > 0) {
    if (grid[x - 1][y] == 'x' || grid[x - 1][y] == '@') {
      grid[x - 1][y] = '.';
      zeroConnected(x - 1, y);
    }
  }
  if (x < n - 1) {
    if (grid[x + 1][y] == 'x' || grid[x + 1][y] == '@') {
      grid[x + 1][y] = '.';
      zeroConnected(x + 1, y);
    }
  }
  if (y > 0) {
    if (grid[x][y - 1] == 'x' || grid[x][y - 1] == '@') {
      grid[x][y - 1] = '.';
      zeroConnected(x, y - 1);
    }
  }
  if (y < n - 1) {
    if (grid[x][y + 1] == 'x' || grid[x][y + 1] == '@') {
      grid[x][y + 1] = '.';
      zeroConnected(x, y + 1);
    }
  }
}

void solve(int c) {
  cin >> n;
  grid.resize(n);
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      char s;
      cin >> s;
      grid[x].push_back(s);
    }
  }
  int sum = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (grid[x][y] == 'x') {
        zeroConnected(x, y);
        sum++;
      }
    }
  }
  printf("Case %d: %d\n", c + 1, sum);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    grid.clear();
    solve(i);
    printf("\n");
  }
}
