#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string, int> goals;
  int n;
  cin >> n;
  int most = 0;
  string win;
  for (int i = 0; i < n; i++) {
    string team;
    cin >> team;
    goals[team]++;
    if (goals[team] > most) {
      win = team;
      most = goals[team];
    }
  }
  cout << win << endl;
}
