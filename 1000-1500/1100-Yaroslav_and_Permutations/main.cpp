#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, int> num_of_nums;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    num_of_nums[num]++;
  }
  for (auto kv : num_of_nums) {
    if (kv.second > ceil(n / 2.0)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
