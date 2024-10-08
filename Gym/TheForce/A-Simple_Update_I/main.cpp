#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    string b;
    cin >> b;
    int c = count(b.begin(), b.end(), '1');
    cout << max<int>(c, (n - k)) << endl;
  }
}
