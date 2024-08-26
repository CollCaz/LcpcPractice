#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int t = 0;
  cin >> t;
  int c1 = 0, c2 = 0, c3 = 0;
  int f1 = 0, f2 = 0, f3 = 0;
  map<int, vector<int>> stm;
  for (int i = 0; i < t; i++) {
    int s;
    cin >> s;
    if (s == 1)
      c1++;
    else if (s == 2)
      c2++;
    else
      c3++;
    stm[s].push_back(i);
  }
  int tc = min(min(c1, c2), c3);
  cout << tc << "\n";
  for (int i = 0; i < tc; i++) {
    int t1, t2, t3;
    t1 = stm[1][i] + 1;
    t2 = stm[2][i] + 1;
    t3 = stm[3][i] + 1;
    cout << t1 << " " << t2 << " " << t3 << endl;
		f1++;
		f2++;
		f3++;
  }
}
