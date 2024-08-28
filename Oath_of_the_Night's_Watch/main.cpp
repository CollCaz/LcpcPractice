#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ss;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    ss.push_back(s);
  }
  sort(ss.begin(), ss.end());
  int mi = ss[0];
  int ma = ss[ss.size() - 1];
	int c = 0;
	for (int i : ss) {
		if (i != mi && i != ma) {
			c++;
		}
	}
	cout << c << endl;
}
