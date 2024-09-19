#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef map<char, vector<char>> graph;

graph g;

map<char, int> values{{'A', 1}, {'B', 1}, {'C', 1}};

bool compCoin(const char &a, const char &b) { return values[a] < values[b]; }

set<char> visited;
bool check(char c) {
  if (visited.count(c) > 0) {
    return false;
  }
  visited.insert(c);
  for (char cn : g[c]) {
    return check(cn);
  }
  return true;
}

int main() {
  vector<char> coinNames;
  for (int i = 0; i < 3; i++) {
    coinNames.push_back('A' + i);
    string wr;
    cin >> wr;
    if (wr[1] == '>') {
      g[wr[0]].push_back(wr[2]);
      values[wr[0]] += values[wr[2]];
    } else {
      g[wr[2]].push_back(wr[0]);
      values[wr[2]] += values[wr[0]];
    }
  }
  for (int i = 'A'; i <= 'C'; i++) {
    if (!check(i)) {
      cout << "Impossible" << endl;
      return 0;
    }
    visited.clear();
  }
  sort(coinNames.begin(), coinNames.end(), compCoin);
  for (char n : coinNames) {
    cout << n;
  }
}
