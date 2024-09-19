#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> pylons;
  int e = 0;
  int spent = 0;
	pylons.push_back(0);
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    pylons.push_back(p);
  }
  for (int i = 0; i < n; i++) {
    int dk = pylons[i] - pylons[i + 1];
    if (dk > 0) {
      e += dk;
      continue;
    }
    if (dk < 0) {
      if (e >= abs(dk)) {
        e += dk;
				continue;
      } else {
				int er = abs(e - abs(dk));
				spent += er;
				e = 0;
			}
    }
  }
	cout << spent << endl;
}
