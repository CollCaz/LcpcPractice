#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> line;
  line.push_back(0);
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    line.push_back(e);
  }
  bool r = false;
  bool rEnded = false;
  int s = 0;
  int e = 0;
  bool good = false;
  bool preSorted = false;
  // 3 1 2 4$
  //   s e
  for (int i = 1; i <= n; i++) {
    // cout << line[i] << " < " << line[i - 1] << endl;
    if (rEnded && line[i] < line[i - 1]) {
      good = false;
    }
    if (!r && line[i] < line[i - 1]) {
      r = true;
      s = i - 1;
    }
    if (r && !rEnded && line[i] > line[i - 1]) {
      rEnded = true;
			good = true;
      e = i - 1;
    }
		if (rEnded) {
			cout << s << endl;
			if (s > 0) {
				if (line[e] < line[s-1]) {
					good = false;
				}
			}
		}
    if (i == n && !r) {
      preSorted = true;
      good = true;
    }
  }
  if (good) {
    cout << "yes" << endl;
    if (preSorted) {
      s = e = 1;
    } else if (s == 0) {
      s = 1;
    }
    if (e < s) {
      e = n;
    }
    cout << s << " " << e << endl;
  } else {
    cout << "no" << endl;
  }
}
