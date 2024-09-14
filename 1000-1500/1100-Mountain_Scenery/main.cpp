#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int changed = 0;
  vector<int> peaks;
  for (int i = 1; i <= (n * 2) + 1; i++) {
    int peak;
    cin >> peak;
    peaks.push_back(peak);
  }
  for (int i = 0; i < peaks.size(); i++) {
    if (i % 2 != 0 && changed < k) {
      if (peaks[i] > 0 && peaks[i]-1 > peaks[i+1] && peaks[i-1] < peaks[i]-1) {
        peaks[i] -= 1;
        changed++;
      }
    }
    cout << peaks[i];
    if (i != (n * 2) + 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
